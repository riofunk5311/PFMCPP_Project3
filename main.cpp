  /*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Homebuilding
{
    int numNailGuns = 5;
    int numPaintSupplies = 10;
    int numVaccumCleaners = 3;
    int numWoodNeeded = 35;
    int numSanders = 4;
    int nailsPerWood = 5;
    int nailUsed = numWoodNeeded * nailsPerWood; 
    Homebuilding();

    int paintWall(int gallonOfPaint = 2); 
    void polishSurface(int pieceOfWood);
    void punchNail();
};

Homebuilding::Homebuilding()
{
    std::cout << "Homebuilding being constructed!" << std::endl;
}

int Homebuilding::paintWall(int gallonOfPaint)
{
    return 2 * gallonOfPaint;  // using a half size of paint can to paint
}

void Homebuilding::polishSurface(int pieceOfWood)
{
    --pieceOfWood;
}

void Homebuilding::punchNail()
{
    std::cout << "Homebuilding::punchNail() " << nailUsed << std::endl;
}

struct CustomBuildPc
{
    int numOfCpus = 3;
    int amountOfRamInGb = 32;
    int amountOfHddInGb = 2000;
    int numberOfOs = 1;
    int amountOfWattage = 600;
    int photo = 50;
    CustomBuildPc();

    struct Cpu
    {
        float clockSpeedInGhz = 2.8f;
        int numCpuCore = 2;
        int numPhysicalCpus = 4;
        std::string manufacturer = "Intel";
        std::string model = "Xeon";
        std::string program = "Photoshop";
        Cpu();

        void runProgram();
        float powerConsume(float timeCpuRunningInMinutes, int cpuUsage, bool multiThreadingOn = true);
        float getTimeToCompile(float sizeOfFile, std::string compileError);
    };

    void writeProgram(std::string language);
    void createVideo(Cpu& cpuB, std::string nameOfCpu);
    void editPhoto();

    Cpu cpuNotInUse;
};

CustomBuildPc::CustomBuildPc()
{
    std::cout << "CustomBuildPc being constructed!" << std::endl;
}

CustomBuildPc::Cpu::Cpu()
{
    std::cout << "Cpu being constructed!" << std::endl;
}

void CustomBuildPc::Cpu::runProgram()
{
    std::cout << "CustonBuildPc::Cpu::runProgram() " << program << std::endl;
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

void CustomBuildPc::writeProgram(std::string language)
{
    std::cout << language << std::endl;
}

void CustomBuildPc::createVideo(Cpu &cpuB, std::string nameOfCpu)
{
     std::cout << cpuB.numCpuCore << nameOfCpu << std::endl;
}

void CustomBuildPc::editPhoto()
{
    std::cout << "CustomBuildPc::editPhoto() " << photo << std::endl;
}

struct PhotoShoot
{
    int numCameras = 4;
    int amountOfMemoryCard = 512;
    int numHariMakeUpArtists = 2;
    float amountOfClothes = 25.0f;
    int numModel = 6;
    std::string nameOfCompanies = "Apple";
    PhotoShoot();

    struct Camera
    {
        double shutterSpeed = 0.000125; 
        bool isMirrorLess = true;
        std::string brand = "Nikon";
        std::string model = "Z9";
        std::string typeOfLens = "standard";
        Camera();

        void shootVideo();
        void changeLens();
        int takePhoto();
    };    

    void makePr();
    void makeNewFashionStyle(Camera& cameraA);
    int bookStudio(int daysToShoot, int numOfCrews);
};

PhotoShoot::PhotoShoot()
{
    std::cout << "PhotoShoot being constructed!" << std::endl;
}

PhotoShoot::Camera::Camera()
{
    std::cout << "Camera being constructed!" << std::endl;
}

void PhotoShoot::makePr()
{
    std::cout << "PhotoShoot::makePr() " << nameOfCompanies << std::endl;
}

void PhotoShoot::makeNewFashionStyle(Camera &cameraA)
{
    std::cout << cameraA.brand << std::endl;
}

int PhotoShoot::bookStudio(int daysToShoot, int numOfCrews)
{
    std::cout << "We need " << daysToShoot << " studio days and " << numOfCrews << " Crews" << std::endl;
    return 0;
}

void PhotoShoot::Camera::shootVideo()
{
    if ( isMirrorLess == false)
    {
        std::string anotherLens = "parfoca";
    }
}

void PhotoShoot::Camera::changeLens()
{
    std::cout << "PhotoShoot::Camera::changeLens() "<< typeOfLens << std::endl;
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
    MotorcycleRepair();

    void cleanChain(float amountOfLube);
    void changeTires(); 
    void repairCarburetor(bool isStockCarburetor);
};

MotorcycleRepair::MotorcycleRepair()
{
    std::cout << "MotorcycleRepair being constructed!" << std::endl;
}

void MotorcycleRepair::cleanChain(float amountOfLube)
{
    std::cout << amountOfLube << std::endl;
}

void MotorcycleRepair::changeTires()
{
    std::cout << "MotorcycleRepair::changeTires() " << numTires << std::endl;
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
    float improvedFps = 60.0f;
    Memory();

    void numAppRunning(float timeAppRunning, float maxMemoryUsed); 
    void transferData(float peakTransferRate);
    void improveFps();
};

Memory::Memory()
{
    std::cout << "Memory being constructed!" << std::endl;
}

void Memory::numAppRunning(float timeAppRunning, float maxMemoryUsed)
{
    std::cout << timeAppRunning << maxMemoryUsed << std::endl;
}

void Memory::transferData(float peakTransferRate)
{
    std::cout << peakTransferRate << std::endl;
}

void Memory::improveFps()
{
     std::cout << "Memory::improveFps() " << improvedFps << std::endl;
}

struct Keyboard
{
    int numKeysTyped = 20;
    float distanceKeyTravel = 15.0f;
    std::string keyLanguage = "US";
    float bluetoothChannel = 2.0f;
    int numUsbPorts = 2;
    int characterTyped = 19;
    Keyboard();

    int typeCharacters();
    void connectToUsb(int numPortsConnected);
    void sendKeyCommands(int keyInput, std::string keyLayout);
};

Keyboard::Keyboard()
{
    std::cout << "Keyboard being constructed!"<< std::endl;
}

int Keyboard::typeCharacters()
{
    std::cout << "Keyboard::typeCharacters() " << characterTyped << std::endl;
    return characterTyped;
}

void Keyboard::connectToUsb(int numPortsConnected)
{
    if ( numPortsConnected == 2 )
    {
        std::cout << "All USB Ports Are Connected" << std::endl;
    }
}

void Keyboard::sendKeyCommands(int keyInput, std::string keyLayout)
{
    if ( keyInput == 109 )
    {
        std::cout << "It is Apple Keyboard " << keyLayout << std::endl;
    }
}

struct Battery
{
    float batteryPower = 69.6f;
    float chargeBattery = 1.5f;
    int numBattery = 1;
    float peakWattage = 96.0f;
    float sizeOfBattery = 1400;
    int devicesBeingCharged = 3;
    Battery();

    void keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower);
    float storeElectricalPower(float currentBatteryPower, float currentWattsInUse); 
    int chargeOtherDevices();
};

Battery::Battery()
{
    std::cout << "Battery being constructed!" << std::endl;
}

void Battery::keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower)
{
    std::cout << "CPU Average Power Consumption: " << cpuAveragePowerConsumption << "CPU Average Power: " << cpuAveragePower << std::endl;
}

float Battery::storeElectricalPower(float currentBatteryPower, float currentWattsInUse)
{
    return currentBatteryPower - currentWattsInUse;
}

int Battery::chargeOtherDevices()
{
    std::cout << "Battery::chargeOtherDevices() " << devicesBeingCharged << std::endl;
    return devicesBeingCharged;
}

struct Trackpad
{
    int depthOfTrackpad = 1149;
    int widthOfTrackpad = 1600;
    double trackpadSensitivity = 5.00; 
    float cursorAcceleration = 2.0f;
    int numConductors = 2;
    bool trackPadClicked = true;
    Trackpad();

    void detectFingerMovement(float xPosition, float yPosition, bool isFingerOn = false);
    int detectPositions(int numFingerTouched, bool isFingerMoved); 
    void detectClick();
};

Trackpad::Trackpad()
{
    std::cout << "Trackpad being constructed!" << std::endl; 
}

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

void Trackpad::detectClick()
{
    std::cout << "Trackpad::detectClick() "<< trackPadClicked << std::endl;
}

struct SSD
{
    int sizeOfSsd = 512;
    float dataTransferSpeed = 100; 
    std::string brand = "Western Digital";
    int numOfSsd = 2;
    int appSize = 128;
    std::string connectionType = "NVMe";
    SSD();

    float readData(float sizeOfFile); 
    float writeData(float sizeOfFile); 
    void installApp();
};

SSD::SSD()
{
    std::cout << "SSD being constructed!" << std::endl;
}

float SSD::readData(float sizeOfFile)
{
    return sizeOfFile / 500.0f;
}

float SSD::writeData(float sizeOfFile)
{
    return sizeOfFile / 800.0f;
}

void SSD::installApp()
{
    int availableSpace = sizeOfSsd - appSize;
    std::cout << "SSD::installApp() " << availableSpace << std::endl;
}

struct Laptop
{
    Memory samsung;
    Keyboard currentKeyboardLayout;
    Battery batteryChargeCycleCount;
    Trackpad externalTrackpadIsConnected;
    SSD Toshiba;
    std::string fontName = "Helvetica";
    Laptop();

    int runProgram(int numAppsInstalled, int maxMemoryAppUse); 
    void displayFonts();
    void calculateAlgorithm(bool isWrittenInCpp);
};

Laptop::Laptop()
{
    std::cout << "Laptop being constructed!" << std::endl;
}

int Laptop::runProgram(int numAppsInstalled, int maxMemoryAppUse)
{
    std::cout << "Max Memory An App Uses: " << maxMemoryAppUse << std::endl;
    return numAppsInstalled;
}

void Laptop::displayFonts()
{
    std::cout << "Laptop::displayFonts() " << fontName << std::endl;
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
    Example::main();

    Homebuilding homebuilding;
    homebuilding.punchNail();
    homebuilding.paintWall(3);
    homebuilding.polishSurface(4);

    std::cout << "You used " << homebuilding.nailUsed << " nails" << std::endl;
    
    CustomBuildPc customBuildPc;
    CustomBuildPc::Cpu cpu;
    
    customBuildPc.editPhoto();
    customBuildPc.writeProgram("C++");
    customBuildPc.createVideo(cpu, "AMD");

    std::cout << "You edited "<< customBuildPc.photo << " photos" << std::endl;

    cpu.runProgram();
    cpu.powerConsume(10, 40, true);
    cpu.getTimeToCompile(150.0f, "Compile Error");

    PhotoShoot photoShoot;
    PhotoShoot::Camera camera;

    photoShoot.makeNewFashionStyle(camera);
    photoShoot.makePr();
    photoShoot.bookStudio(8, 20);

    camera.changeLens();
    camera.shootVideo();
    camera.takePhoto();
    
    MotorcycleRepair motorCycleRepair;
    motorCycleRepair.changeTires();
    motorCycleRepair.cleanChain(3.7f);
    motorCycleRepair.repairCarburetor(true);

    Memory memory;
    memory.improveFps();
    memory.numAppRunning(9.30f, 256.0f);
    memory.transferData(60.0f);

    Keyboard keyboard;
    keyboard.typeCharacters();
    keyboard.connectToUsb(3);
    keyboard.sendKeyCommands(10, "US-EN");

    std::cout << "How many characters are typed? " << keyboard.characterTyped << std::endl;

    Battery battery;
    battery.chargeOtherDevices();
    battery.keepCpuRunning(25.0f, 45.0f);
    battery.storeElectricalPower(3500.0f, 45.5f);

    Trackpad trackPad;
    trackPad.detectClick();
    trackPad.detectFingerMovement(100.0f, 210.0f, false);
    trackPad.detectPositions(2, true); 

    SSD ssd;
    ssd.installApp();
    ssd.readData(18.0f);
    ssd.writeData(10.0f);

    Laptop laptop;
    laptop.displayFonts();
    laptop.runProgram(15, 5000);
    laptop.calculateAlgorithm(true);

    std::cout << "Is the font Helvetica? " << (laptop.fontName == "Helvetica" ? "True" : "False" ) << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
