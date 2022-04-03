/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct Homebuilding
{
    int numNailGuns = 5;
    int numPaintSupplies = 10;
    int numWoodNeeded { 35 };
    int nailsPerWood = 5;
    int nailUsed = numWoodNeeded * nailsPerWood; 

    Homebuilding();
    int numSanders;
    int numVaccumCleaners;

    
    int paintWall(int gallonOfPaint = 2); 
    void polishSurface(int pieceOfWood);
    void punchNail();
};

Homebuilding::Homebuilding() : 
numSanders(4),
numVaccumCleaners(3)
{
    std::cout << "Homebuilding being constructed!" << std::endl;
}

int Homebuilding::paintWall(int gallonOfPaint)
{
    return 2 * gallonOfPaint;  // using a half size of paint can to paint
}

void Homebuilding::polishSurface(int pieceOfWood)
{
    std::cout << "Number of Sanders: " << numSanders << "\nNumber of Vacuum Cleaners: "<< numVaccumCleaners <<  std::endl;
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
    int amountOfHddInGb;
    int numberOfOs = 1;
    int amountOfWattage;
    int photo = 50;

    CustomBuildPc();

    struct Cpu
    {
        int numCpuCore = 2;
        std::string manufacturer = "Intel";
        std::string model = "Xeon";
        std::string program = "Photoshop";

        Cpu();
        int numPhysicalCpus;
        float clockSpeedInGhz;

        void runProgram();
        float powerConsume(float timeCpuRunningInMinutes, int cpuUsage, bool multiThreadingOn = true);
        float getTimeToCompile(float sizeOfFile, std::string compileError);
    };

    void writeProgram(std::string language);
    void createVideo(Cpu& cpuB, std::string nameOfCpu);
    void editPhoto();

    Cpu cpuNotInUse;
};

CustomBuildPc::CustomBuildPc() : 
amountOfHddInGb(2000), 
amountOfWattage(600)
{
    std::cout << "CustomBuildPc being constructed!" << std::endl;
}

CustomBuildPc::Cpu::Cpu() : 
numPhysicalCpus(4),
clockSpeedInGhz(2.8f)
{
    std::cout << "Cpu being constructed!" << std::endl;
}

void CustomBuildPc::Cpu::runProgram()
{
    std::cout << "Cpu is running at " << clockSpeedInGhz << " Hz" << " on " << numPhysicalCpus << " CPUs" <<  std::endl;
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
     std::cout << cpuB.numCpuCore << "\n" << nameOfCpu << std::endl;
}

void CustomBuildPc::editPhoto()
{
    std::cout << "Amount of wattage: " << amountOfWattage << std::endl;
    std::cout << "CustomBuildPc::editPhoto() " << photo << std::endl;
}

struct PhotoShoot
{
    int numCameras = 4;
    int numHariMakeUpArtists = 2;
    int numModel = 6;
    std::string nameOfCompanies = "Apple";

    PhotoShoot();
    int amountOfMemoryCard;
    float amountOfClothes;

    struct Camera
    {
        double shutterSpeed { 0.000125 }; 
        bool isMirrorLess = true;
        std::string brand = "Nikon";
        std::string model;
        std::string typeOfLens;
        Camera();

        void shootVideo();
        void changeLens();
        int takePhoto();
    };    

    void makePr();
    void makeNewFashionStyle(Camera& cameraA);
    int bookStudio(int daysToShoot, int numOfCrews);
};

PhotoShoot::PhotoShoot() : 
amountOfMemoryCard(512),
amountOfClothes(25.0f)
{
    std::cout << "PhotoShoot being constructed!" << std::endl;
}

PhotoShoot::Camera::Camera() : 
model("Z9"),
typeOfLens("Standard")
{
    std::cout << "Camera being constructed!" << std::endl;
}

void PhotoShoot::makePr()
{
    std::cout << "PhotoShoot::makePr() " << nameOfCompanies << std::endl;
}

void PhotoShoot::makeNewFashionStyle(Camera &cameraA)
{
    std::cout << "We need " << amountOfMemoryCard << " of Memory Card and " << amountOfClothes << " of clothes" << std::endl;
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

    std::cout << "We use " << model << std::endl;
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
    int numTools;
    float amountOfEngineOil;
    int numTires;
    int numChains;
    int numSprockets;

    MotorcycleRepair();

    void cleanChain(float amountOfLube);
    void changeTires(); 
    void repairCarburetor(bool isStockCarburetor);
};

MotorcycleRepair::MotorcycleRepair() : 
numTools(48),
amountOfEngineOil(25),
numTires(2),
numChains(4),
numSprockets(2)
{
    std::cout << "MotorcycleRepair being constructed!" << std::endl;
}

void MotorcycleRepair::cleanChain(float amountOfLube)
{
    std::cout << "We need "<< amountOfLube << " lube for " << "numChains" << " chains" << std::endl;
}

void MotorcycleRepair::changeTires()
{
    std::cout << "MotorcycleRepair::changeTires() " << numTires << " and " << numSprockets << " sprockets"<< std::endl;
}

void MotorcycleRepair::repairCarburetor(bool isStockCaburetor)
{
    if ( isStockCaburetor == false )
    {
        std::string secondCaburetor = "FCR";
    }

    std::cout << "We need " << numTools << " Tools and " << amountOfEngineOil << " engine oil"<< std::endl;
}

struct Memory
{
    Memory();
    int amountOfRam;
    int numberOfAppsRunning;
    float memoryBusSpeed;
    float ramReadSpeed; 
    float ramWriteSpeed;
    float improvedFps;

    void numAppRunning(float timeAppRunning, float maxMemoryUsed); 
    void transferData(float peakTransferRate);
    void improveFps();
};

Memory::Memory() : 
amountOfRam(64),
numberOfAppsRunning(15),
memoryBusSpeed(800.0f),
ramReadSpeed(40.0f),
ramWriteSpeed(40.0f),
improvedFps(60.0f)
{
    std::cout << "Memory being constructed!" << std::endl;
}

void Memory::numAppRunning(float timeAppRunning, float maxMemoryUsed)
{
    std::cout << timeAppRunning << maxMemoryUsed << std::endl;
}

void Memory::transferData(float peakTransferRate)
{
    std::cout << "Peak Transfer Rate is: " << peakTransferRate << "\nRead and Write Speed: " << ramReadSpeed << " : " << ramWriteSpeed << std::endl;
}

void Memory::improveFps()
{
     std::cout << "Memory::improveFps() " << improvedFps << std::endl;
}

struct Keyboard
{
    Keyboard();
    int numUsbPorts;
    int characterTyped;
    int numKeysTyped;
    float distanceKeyTravel;
    std::string keyLanguage;
    float bluetoothChannel;
   
    int typeCharacters();
    void connectToUsb(int numPortsConnected);
    void sendKeyCommands(int keyInput, std::string keyLayout);
};

Keyboard::Keyboard() : 
numUsbPorts(2),
characterTyped(19),
numKeysTyped(20),
distanceKeyTravel(15.0f),
keyLanguage("US"),
bluetoothChannel(2.0f)
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

    std::cout << numUsbPorts << " usb ports are being used" << std::endl;
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
    float peakWattage = 96.0f;
    float sizeOfBattery = 1400;
    int devicesBeingCharged = 3;

    Battery();
    float batteryPower;
    float chargeBattery;
    int numBattery;

    void keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower);
    float storeElectricalPower(float currentBatteryPower, float currentWattsInUse); 
    int chargeOtherDevices();
};

Battery::Battery() : 
batteryPower(69.6f),
chargeBattery(1.5f),
numBattery(1)
{
    std::cout << "Battery being constructed!" << std::endl;
}

void Battery::keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower)
{
    std::cout << "CPU Average Power Consumption: " << cpuAveragePowerConsumption << "\nCPU Average Power: " << cpuAveragePower << std::endl;
}

float Battery::storeElectricalPower(float currentBatteryPower, float currentWattsInUse)
{
    return currentBatteryPower - currentWattsInUse;
}

int Battery::chargeOtherDevices()
{
    std::cout << "Battery::chargeOtherDevices() " << devicesBeingCharged << " Battery Power is: " << batteryPower << std::endl;
    return devicesBeingCharged;
}

struct Trackpad
{
    Trackpad();
    int depthOfTrackpad = 1149;
    int widthOfTrackpad = 1600;
    double trackpadSensitivity = 5.00; 
    float cursorAcceleration;
    int numConductors;
    bool trackPadClicked;

    void detectFingerMovement(float xPosition, float yPosition, bool isFingerOn = false);
    int detectPositions(int numFingerTouched, bool isFingerMoved); 
    void detectClick();
};

Trackpad::Trackpad() : 
cursorAcceleration(2.0f),
numConductors(2),
trackPadClicked(true)
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

    std::cout << "Cursor Acceleration is: " << cursorAcceleration << std::endl;
    return numFingerTouched;
}

void Trackpad::detectClick()
{
    std::cout << "Trackpad::detectClick() "<< trackPadClicked << std::endl;
}

struct SSD
{
    int sizeOfSsd { 512 };
    float dataTransferSpeed = 100;
    int numOfSsd = 2;
    int appSize = 128;
    
    SSD();
    std::string brand;
    std::string connectionType;

    float readData(float sizeOfFile); 
    float writeData(float sizeOfFile); 
    void installApp();
};

SSD::SSD() : 
brand("Western Digital"),
connectionType("NVMe")
{
    std::cout << "SSD being constructed!" << std::endl;
}

float SSD::readData(float sizeOfFile)
{
    std::cout << "SSD connection type is: " << connectionType << std::endl;
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
