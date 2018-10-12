##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Funciones
ConfigurationName      :=Debug
WorkspacePath          := "/home/equipo/Desarrollo/C/ClashClans"
ProjectPath            := "/home/equipo/Desarrollo/C/MetaH/Funciones"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=equipo
Date                   :=08/31/15
CodeLitePath           :="/home/equipo/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Funciones.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/esfera.c$(ObjectSuffix) $(IntermediateDirectory)/ackley.c$(ObjectSuffix) $(IntermediateDirectory)/algoritmo.c$(ObjectSuffix) $(IntermediateDirectory)/hill_climbing.c$(ObjectSuffix) $(IntermediateDirectory)/griewank.c$(ObjectSuffix) $(IntermediateDirectory)/rastrigin.c$(ObjectSuffix) $(IntermediateDirectory)/schwefel.c$(ObjectSuffix) $(IntermediateDirectory)/r_restarts.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/esfera.c$(ObjectSuffix): esfera.c $(IntermediateDirectory)/esfera.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/esfera.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/esfera.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/esfera.c$(DependSuffix): esfera.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/esfera.c$(ObjectSuffix) -MF$(IntermediateDirectory)/esfera.c$(DependSuffix) -MM "esfera.c"

$(IntermediateDirectory)/esfera.c$(PreprocessSuffix): esfera.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/esfera.c$(PreprocessSuffix) "esfera.c"

$(IntermediateDirectory)/ackley.c$(ObjectSuffix): ackley.c $(IntermediateDirectory)/ackley.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/ackley.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ackley.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ackley.c$(DependSuffix): ackley.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ackley.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ackley.c$(DependSuffix) -MM "ackley.c"

$(IntermediateDirectory)/ackley.c$(PreprocessSuffix): ackley.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ackley.c$(PreprocessSuffix) "ackley.c"

$(IntermediateDirectory)/algoritmo.c$(ObjectSuffix): algoritmo.c $(IntermediateDirectory)/algoritmo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/algoritmo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algoritmo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algoritmo.c$(DependSuffix): algoritmo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algoritmo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/algoritmo.c$(DependSuffix) -MM "algoritmo.c"

$(IntermediateDirectory)/algoritmo.c$(PreprocessSuffix): algoritmo.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algoritmo.c$(PreprocessSuffix) "algoritmo.c"

$(IntermediateDirectory)/hill_climbing.c$(ObjectSuffix): hill_climbing.c $(IntermediateDirectory)/hill_climbing.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/hill_climbing.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hill_climbing.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hill_climbing.c$(DependSuffix): hill_climbing.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hill_climbing.c$(ObjectSuffix) -MF$(IntermediateDirectory)/hill_climbing.c$(DependSuffix) -MM "hill_climbing.c"

$(IntermediateDirectory)/hill_climbing.c$(PreprocessSuffix): hill_climbing.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hill_climbing.c$(PreprocessSuffix) "hill_climbing.c"

$(IntermediateDirectory)/griewank.c$(ObjectSuffix): griewank.c $(IntermediateDirectory)/griewank.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/griewank.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/griewank.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/griewank.c$(DependSuffix): griewank.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/griewank.c$(ObjectSuffix) -MF$(IntermediateDirectory)/griewank.c$(DependSuffix) -MM "griewank.c"

$(IntermediateDirectory)/griewank.c$(PreprocessSuffix): griewank.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/griewank.c$(PreprocessSuffix) "griewank.c"

$(IntermediateDirectory)/rastrigin.c$(ObjectSuffix): rastrigin.c $(IntermediateDirectory)/rastrigin.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/rastrigin.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rastrigin.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rastrigin.c$(DependSuffix): rastrigin.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rastrigin.c$(ObjectSuffix) -MF$(IntermediateDirectory)/rastrigin.c$(DependSuffix) -MM "rastrigin.c"

$(IntermediateDirectory)/rastrigin.c$(PreprocessSuffix): rastrigin.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rastrigin.c$(PreprocessSuffix) "rastrigin.c"

$(IntermediateDirectory)/schwefel.c$(ObjectSuffix): schwefel.c $(IntermediateDirectory)/schwefel.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/schwefel.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/schwefel.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/schwefel.c$(DependSuffix): schwefel.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/schwefel.c$(ObjectSuffix) -MF$(IntermediateDirectory)/schwefel.c$(DependSuffix) -MM "schwefel.c"

$(IntermediateDirectory)/schwefel.c$(PreprocessSuffix): schwefel.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/schwefel.c$(PreprocessSuffix) "schwefel.c"

$(IntermediateDirectory)/r_restarts.c$(ObjectSuffix): r_restarts.c $(IntermediateDirectory)/r_restarts.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/equipo/Desarrollo/C/MetaH/Funciones/r_restarts.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/r_restarts.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/r_restarts.c$(DependSuffix): r_restarts.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/r_restarts.c$(ObjectSuffix) -MF$(IntermediateDirectory)/r_restarts.c$(DependSuffix) -MM "r_restarts.c"

$(IntermediateDirectory)/r_restarts.c$(PreprocessSuffix): r_restarts.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/r_restarts.c$(PreprocessSuffix) "r_restarts.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../ClashClans/.build-debug/Funciones"


