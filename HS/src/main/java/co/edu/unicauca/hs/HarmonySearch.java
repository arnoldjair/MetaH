package co.edu.unicauca.hs;

import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import co.edu.unicauca.hs.exception.DistanceException;
import co.edu.unicauca.hs.model.JsonParams;
import co.edu.unicauca.hs.model.Result;
import co.edu.unicauca.hs.model.task.Task;
import co.edu.unicauca.hs.service.Config;
import co.edu.unicauca.hs.utils.Report;
import co.edu.unicauca.hs.model.task.TaskBuilder;
import gnu.getopt.Getopt;

/**
 * Spring
 */
/**
 *
 * @author equipo
 */
public class HarmonySearch {

    public static void main(String[] args) throws DistanceException, Exception {
    	Locale.setDefault(new Locale("es", "CO"));
    	Getopt go = new Getopt("Harmony search", args, "p:");
    	int c;
    	JsonParams params = null;
    	Map<String, Object> tmpMap = new HashMap<>();
    	GsonBuilder builder = new GsonBuilder();
        Gson gson = builder.create();
    	
    	while ((c = go.getopt()) != -1) {
            switch (c) {
            case 'p':
                tmpMap = gson.fromJson(new FileReader(go.getOptarg()), tmpMap.getClass());
                params = new JsonParams();
                params.setMap(tmpMap);
                if (!params.verifyExperiment()) {
                    throw new Exception("Error en los parámetros");
                }
                break;
            }
    	}
    	
    	Config.getInstance().initResultFolder();    	
    }
    
    public static void experiment(JsonParams params) throws Exception {
        long milis = System.currentTimeMillis();
        Report report = new Report("Reporte.csv", true);
        try {

            SimpleDateFormat dFormat = new SimpleDateFormat("dd-MM-yyyy_HH:mm:ss");

            int maxT = 4;
            ExecutorService pool = Executors.newFixedThreadPool(maxT);
            List<Future<Result>> futureObjs = new ArrayList<Future<Result>>();
            List<Task> tasks = TaskBuilder.buildTasks(params);
            List<Result> results = new ArrayList<Result>();

            for (Task task : tasks) {
                GBHSExperimenter exp = new GBHSExperimenter(task);
                Future<Result> future = pool.submit(exp);
                futureObjs.add(future);
            }

            for (Future<Result> futureObj : futureObjs) {
                results.add(futureObj.get());
            }

            pool.shutdown();

            StringBuilder sb = new StringBuilder();
            sb.append("date").append("\t")
                    .append("averageIcc").append("\t")
                    .append("averageIic").append("\t")
                    .append("averageEr").append("\t")
                    .append("standardDeviation").append("\t")
                    .append("dataset").append("\t")
                    .append("objectiveFunction").append("\t")
                    .append("distance").append("\t")
                    .append("algorithm").append("\t")
                    .append(params.getFields()).append("\n");
            report.writeLine(sb.toString());
            Date date = new Date();
            for (Result result : results) {
                sb = new StringBuilder();
                sb.append(dFormat.format(date)).append("\t")
                        .append(result.toString()).append("\t")
                        .append(params.toString()).append("\n");
                report.writeLine(sb.toString());
            }

        } catch (InterruptedException | ExecutionException ex) {
            Logger.getLogger(HarmonySearch.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            milis = System.currentTimeMillis() - milis;
            report.writeLine("tiempo\t" + milis + "\tmilis\n\n");
            System.out.println("tiempo\t" + milis + "\tmilis");
            report.close();
        }

    }
}
