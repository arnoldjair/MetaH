package co.edu.unicauca.gbhs.service;

import java.io.File;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 *
 * @author equipo
 */
public class Config {

    private File resultFolder;
    private Random random;
    private boolean init;
    private Map<String, String> configurations;

    private Config() {
        init = false;
        this.configurations = new HashMap<>();
    }

    public static Config getInstance() {
        return InfoHolder.INSTANCE;
    }

    private static class InfoHolder {

        private static final Config INSTANCE = new Config();
    }

    public synchronized void initResultFolder() {
        if (!init) {

            String nCarpetaResultado = "Resultado";
            resultFolder = new File(nCarpetaResultado);
            resultFolder.mkdir();
            init = true;
        }
    }

    public synchronized File getResultFolder() {
        return resultFolder;
    }

    public synchronized void setRandom(Random random) {
        this.random = random;
    }

    public synchronized Random getRandom() {
        return random;
    }

    public synchronized String getConfig(String config) {
        return this.configurations.getOrDefault(config, null);
    }

    public synchronized void setConfig(String key, String value) {
        this.configurations.put(key, value);
    }

}
