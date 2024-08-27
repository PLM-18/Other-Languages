#include <iostream>
#include <map>

class BattleStrategy{
    public:
        virtual void execute() = 0;
        virtual int getSuccessRate() = 0;
};

class Fortification : public BattleStrategy{
    private:
        int successRate = 0;
    public:
        void execute(){
            if(successRate == 0){
                successRate = 98;
            }
            std::cout << "Fortification strategy with: "<< successRate << std::endl;
        }

        int getSuccessRate(){
            return successRate;
        }
};

class Flanking : public BattleStrategy{
    private:
        int successRate = 0;
    public:
        void execute(){
            if(successRate == 0){
                successRate = 87;
            }
            std::cout << "Flanking strategy with: " << successRate<< std::endl;
        }

        int getSuccessRate(){
            return successRate;
        }
};

class Ambush : public BattleStrategy{
    private:
        int successRate = 0;
    public:
        void execute(){
            if(successRate == 0){
                successRate = 90;
            }
            std::cout << "Ambush strategy  with: "<< successRate << std::endl;
        }

        int getSuccessRate(){
            return successRate;
        }
};

class TacticalMemento{
    private:
        BattleStrategy* strategy;
    public:
        TacticalMemento(BattleStrategy* strategy){
            this->strategy = strategy;
        }

        TacticalMemento(){
            this->strategy = nullptr;
        }

        void storeStrategy(BattleStrategy* strategy){
            this->strategy = strategy;
        }
        
        BattleStrategy* getStrategy(){
            return strategy;
        }
};

class TacticalPlanner{
    private:
        BattleStrategy* strategy;
    public:
        TacticalMemento* createMemento(){
            return new TacticalMemento(strategy);
        }

        void setMemento(TacticalMemento* memento){
            strategy = memento->getStrategy();
        }
};

class WarArchive{
    private:
        std::map<std::string, TacticalMemento*> archive;
    public:
        void addMemento(std::string key, TacticalMemento* memento){
            archive[key] = memento;
        }

        void removeMemento(std::string key){
            archive.erase(key);
        }

        TacticalMemento* getBestMemento(){
            TacticalMemento* bestMemento = nullptr;
            int bestRate = 0;

            for(auto it = archive.begin(); it != archive.end(); it++){
                if(it->second->getStrategy()->getSuccessRate() > bestRate){
                    bestRate = it->second->getStrategy()->getSuccessRate();
                    bestMemento = it->second;
                }
            }

            return bestMemento;
        }

        void printArchive(){
            for(auto it = archive.begin(); it != archive.end(); it++){
                std::cout << it->first <<"with the rating "<<it->second->getStrategy()->getSuccessRate()<< std::endl;
            }
        }

        ~WarArchive(){
            for(auto it = archive.begin(); it != archive.end(); it++){
                delete it->second;
            }
        }	
};

class TacticalCommand{
    private:
        TacticalMemento* memento = nullptr;
        WarArchive* warArchive = nullptr;
    public:
        TacticalCommand(){
            warArchive = new WarArchive();
        }

        void setStrategy(BattleStrategy* strategy, std::string key){
            this->memento->storeStrategy(strategy);
            this->warArchive->addMemento(key, memento);
        }

        void printArchive(){
            warArchive->printArchive();
        }
        
        void execute(){
            if(memento)
            memento->getStrategy()->execute();
        }

        void executeBestStrategy(){
            BattleStrategy* bestStrategy = nullptr;
            bestStrategy = warArchive->getBestMemento()->getStrategy();
            memento->storeStrategy(bestStrategy);
            std::cout << "Best strategy executed: " << std::endl;
            bestStrategy->execute();
        }

        ~TacticalCommand(){
            if(memento) delete memento;
            delete warArchive;
        }
};

int main(){
    TacticalPlanner* tacticalPlanner = new TacticalPlanner();
    WarArchive* warArchive = new WarArchive();
    TacticalCommand* tacticalCommand = new TacticalCommand();

    BattleStrategy* fortification = new Fortification();
    BattleStrategy* flanking = new Flanking();
    BattleStrategy* ambush = new Ambush();

    tacticalPlanner->setMemento(tacticalPlanner->createMemento());
    tacticalCommand->setStrategy(fortification, "fortification");
    tacticalCommand->execute();
    warArchive->addMemento("fortification", tacticalPlanner->createMemento());

    tacticalPlanner->setMemento(tacticalPlanner->createMemento());
    tacticalCommand->setStrategy(flanking, "flanking");
    tacticalCommand->execute();
    warArchive->addMemento("flanking", tacticalPlanner->createMemento());

    tacticalPlanner->setMemento(tacticalPlanner->createMemento());
    tacticalCommand->setStrategy(ambush, "ambush");
    tacticalCommand->execute();
    warArchive->addMemento("ambush", tacticalPlanner->createMemento());

    tacticalCommand->executeBestStrategy();
    tacticalCommand->printArchive();


    return 0;
}