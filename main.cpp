 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTraveled;

    struct Foot
    {
        int numSteps = 0;
        float inseam = 34.0f;  
        std::string primaryLeg = "right leg";
        float footSize = 8.5f;

        void stepForward();
        float stepSize();
    };

    Foot rightFoot;
    Foot leftFoot;

    void run( float howFast, bool startWithleftFoot);
};

void Person::Foot::stepForward()
{
    ++numSteps;
}

float Person::Foot::stepSize()
{
    return footSize;
}

void Person::run(float howNotSlow, bool startWithLeftFoot)
{
    if ( startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howNotSlow = distanceTraveled / ( leftFoot.stepSize() + rightFoot.stepSize() );
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

struct Homebuilding
{
    int numNailGuns = 5;
    int numPaintSupplies = 10;
    int numVaccumCleaners = 3;
    int numWoodNeeded = 35;
    int numSanders = 4;

    int paintWall(int gallonOfPaint); 
    void polishSurface(int pieceOfWood);
    void punchNail(int boxOfNail);
};

int Homebuilding::paintWall(int gallonOfPaint)
{
    return 2 * gallonOfPaint;  // using a half size of paint can to paint
}

void polishSurface(int pieceOfWood)
{
    --pieceOfWood;
}

void punchNail(int boxOfNail)
{
    --boxOfNail;
}

struct CustomBuildPc
{
    int numOfCpus = 3;
    int amountOfRamInGb = 32;
    int amountOfHddInGb = 2000;
    int numberOfOs = 1;
    int amountOfWattage = 600;

    struct Cpu
    {
        float clockSpeedInGhz = 2.8f;
        int numCpuCore = 2;
        int numPhysicalCpus = 4;
        std::string manufacturer = "Intel";
        std::string model = "Xeon";

        void runProgram(int memoryUse, float wattageConsumption, float cpuTemp);
        float powerConsume(float timeCpuRunningInMinutes, int cpuUsage, bool multiThreadingOn = true);
        float getTimeToCompile(float sizeOfFile, std::string compileError);
    };

    void writeProgram(Cpu cpuA);
    void createVideo(Cpu cpuB);
    void editPhoto(std::string appToUse, float memoryUsage);

    Cpu cpuNotInUse;
};

void CustomBuildPc::Cpu::runProgram(int memoryUse, float wattageConsumption, float cpuTemp)
{
    if ( wattageConsumption > 80.0f && cpuTemp > 85.0f )
    {
        std::cout << "Memory is now being used: " << memoryUse << std::endl;
    }
}

float CustomBuildPc::Cpu::powerConsume(float timeCpuRunningInMinutes, int cpuUsage, bool multiThreadingOn)
{
    if ( multiThreadingOn == true && cpuUsage == 5 )
    {
        std::cout << "Power Consumption is high" << std::endl;
    }
    return clockSpeedInGhz * timeCpuRunningInMinutes;
}

float CustomBuildPc::Cpu::getTimeToCompile(float sizeOfFile, std::string compileError)
{
    if ( sizeOfFile > 100.0f )
    {
        std::cout << compileError << std::endl;
    }
    
    return sizeOfFile;
}

void CustomBuildPc::writeProgram(Cpu cpuA)
{
     cpuA = cpuNotInUse;
}

void CustomBuildPc::createVideo(Cpu cpuB)
{
     cpuB = cpuNotInUse;
}

void CustomBuildPc::editPhoto(std::string appToUse, float memoryUsage)
{
    if ( memoryUsage > 85 )
    {
        std::cout << appToUse << std::endl;
    }
}

struct PhotoShoot
{
    int numCameras = 4;
    int amountOfMemoryCard = 512;
    int numHariMakeUpArtists = 2;
    float amountOfClothes = 25.0f;
    int numModel = 6;

    struct Camera
    {
        double shutterSpeed = 0.000125; 
        bool isMirrorLess = true;
        std::string brand = "Nikon";
        std::string model = "Z9";
        std::string typeOfLens = "standard";

        void shootVideo();
        void changeLens(std::string nameOfLens);
        int takePhoto();
    };    

    void makePr(std::string nameOfCompanies, std::string nameOfProduct);
    void makeNewFashionStyle(Camera cameraA);
    int bookStudio(int daysToShoot, int numOfCrews);
};

void PhotoShoot::Camera::shootVideo()
{
    if ( isMirrorLess == false)
    {
        std::string anotherLens = "parfoca";
    }
}

void PhotoShoot::Camera::changeLens(std::string nameOfLens)
{
    nameOfLens = "Short telephoto";
}

int PhotoShoot::Camera::takePhoto()
{
    if ( isMirrorLess )
    {
       std::cout << brand << std::endl;
    }
    int photoTaken = 2;
    return photoTaken;
}

struct MotorcycleRepair
{
    int numTools = 48;
    float amountOfEnginOil = 25;
    int numTires = 2;
    int numChains = 4;
    int numSprockets = 2;

    void cleanChain(float amountOfLube);
    int changeTires(bool sizeOfTires, bool blockTire); 
    void repairCarburetor(bool isStockCarburetor);
};

void MotorcycleRepair::cleanChain(float amountOfLube)
{
    std::cout << amountOfLube << std::endl;
}

int MotorcycleRepair::changeTires(bool sizeOfTires, bool blockTire)
{
    if ( sizeOfTires == true && blockTire == false )
    {
        std::cout << "Tires are changed" << std::endl;
    }
    
    int tiresChanged = 2;
    return tiresChanged;
}

void MotorcycleRepair::repairCarburetor(bool isStockCaburetor)
{
    if ( isStockCaburetor == false )
    {
        std::string secondCaburetor = "FCR";
    }
}

struct Memory
{
    int amountOfRam = 64;
    int numberOfAppsRunning = 15;
    float memoryBusSpeed = 800;
    float ramReadSpeed = 40; 
    float ramWriteSpeed = 40;

    void numAppRunning(float timeAppRunning, float maxMemoryUsed); 
    void transferData(float peakTransferRate);
    void improveFps(float fps, float refreshRate);
};

void Memory::numAppRunning(float timeAppRunning, float maxMemoryUsed)
{
    std::cout << timeAppRunning << maxMemoryUsed << std::endl;
}

void transferData(float peakTransferRate)
{
    std::cout << peakTransferRate << std::endl;
}

void improveFps(float fps, float refreshRate)
{
     std::cout << "fps: " << fps << "Refresh Rate: " << refreshRate << std::endl;
}

struct Keyboard
{
    int numKeysTyped = 20;
    float distanceKeyTravel = 15.0f;
    std::string keyLanguage = "US";
    float bluetoothChannel = 2.0f;
    int numUsbPorts = 2;

    int typeCharacters(int wordTypedInMin);
    void connectToUsb(int numPortsConnected);
    void sendKeyCommands(int keyInput, std::string keyLanguage);
};

int Keyboard::typeCharacters(int wordTypedInMin)
{
    return wordTypedInMin;
}

void Keyboard::connectToUsb(int numPortsConnected)
{
    if ( numPortsConnected == 2 )
    {
        std::cout << "All USB Ports Are Connected" << std::endl;
    }
}

void sendKeyCommands(int keyInput, std::string keyLanguage)
{
    if ( keyInput == 109 )
    {
        std::cout << "It is Apple Keyboard" << keyLanguage << std::endl;
    }
}

struct Battery
{
    float batteryPower = 69.6f;
    float chargeBattery = 1.5f;
    int numBattery = 1;
    float peakWattage = 96.0f;
    float sizeOfBattery = 1400;

    void keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower);
    float storeElectricalPower(float currentBatteryPower, float currentWattsInUse); 
    int chargeOtherDevices(int numPortsConnected, int powerDrawn);
};

void Battery::keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower)
{
    std::cout << "CPU Average Power Consumption: " << cpuAveragePowerConsumption << "CPU Average Power: " << cpuAveragePower << std::endl;
}

float Battery::storeElectricalPower(float currentBatteryPower, float currentWattsInUse)
{
    return currentBatteryPower - currentWattsInUse;
}

int chargeOtherDevices(int numPortsConnected, int powerDrawn)
{
    return numPortsConnected * powerDrawn;
}

struct Trackpad
{
    int depthOfTrackpad = 1149;
    int widthOfTrackpad = 1600;
    double trackpadSensitivity = 5.00; 
    float cursorAcceleration = 2.0f;
    int numConductors = 2;

    void detectFingerMovement(float xPosition, float yPosition, bool isFingerOn = false);
    int detectPositions(int numFingerTouched, bool isFingerMoved); 
    void detectClick(float xPositionClicked, float yPositionClicked);
};

void Trackpad::detectFingerMovement(float xPosition, float yPosition, bool isFingerOn)
{
    if ( isFingerOn )
    {
        std::cout << xPosition << yPosition << std::endl;
    }
}

int Trackpad::detectPositions(int numFingerTouched, bool isFingerMoved)
{
    if ( isFingerMoved )
    {
        std::cout << "Fingers movement detected" << std::endl;
    }
    return numFingerTouched;
}

void Trackpad::detectClick(float xPositionClicked, float yPositionClicked)
{
    std::cout << xPositionClicked << yPositionClicked << std::endl;
}

struct SSD
{
    int sizeOfSsd = 512;
    float dataTransferSpeed = 100; 
    std::string brand = "Western Digital";
    int numOfSsd = 2;
    std::string connectionType = "NVMe";

    float readData(float sizeOfFile); 
    float writeData(float sizeOfFile); 
    void installApp(float sizeOfAvailableSpace, float sizeOfApp);
};

float SSD::readData(float sizeOfFile)
{
    return sizeOfFile / 500.0f;
}

float SSD::writeData(float sizeOfFile)
{
    return sizeOfFile / 800.0f;
}

void SSD::installApp(float sizeOfAvailableSpace, float sizeOfApp)
{
    if ( sizeOfAvailableSpace > sizeOfApp )
    {
        std::cout << "Installation will begin shortly" << std::endl;
    }
}

struct Laptop
{
    Memory samsung;
    Keyboard currentKeyboardLayout;
    Battery batteryChargeCycleCount;
    Trackpad externalTrackpadIsConnected;
    SSD Toshiba;

    int runProgram(int numAppsInstalled, int maxMemoryAppUse); 
    void displayFonts(std::string fontName);
    void calculateAlgorithm(bool isWrittenInCpp);
};

int Laptop::runProgram(int numAppsInstalled, int maxMemoryAppUse)
{
    std::cout << "Max Memory An App Uses: " << maxMemoryAppUse << std::endl;
    return numAppsInstalled;
}

void Laptop::displayFonts(std::string fontName)
{
    std::cout << fontName << std::endl;
}

void Laptop::calculateAlgorithm(bool isWrittenCpp)
{
    if ( isWrittenCpp )
    {
        std::cout << "Program will start running" << std::endl;
    }
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
