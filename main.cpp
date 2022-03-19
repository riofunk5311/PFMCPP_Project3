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


/*
1) Homebuilding
5 properties:
    number of nail guns (int)
    number of paint supplies (int)
    number of vacuum cleaners (int)
    the amount of wood needed  (int)
    number of sanders (int)
3 things it can do:
    paint walls
    polish the surface of woods
    punch nails
*/

struct Homebuilding
{
    // number of nail guns
    int numNailGuns = 5;
    // number of paint supplies
    int numPaintSupplies = 10;
    //number of vacuum cleaners
    int numVaccumCleaners = 3;
    // the amount of wood needed
    int numWoodNeeded = 35;
    // number of sanders 
    int numSanders = 4;

    // paint the walls 
    int paintWall(float gallonOfPaint); //return number of walls painted
    // polish the surface of woods
    void polishSurface(int pieceOfWood);
    //  punch nails
    void punchNail(int boxOfNail);
};

/*
2) Custom Built PC
5 properties:
    number of CPUs (int)
    the amount of RAM gb (int)
    the amount of HDD gb (int)
    number of OS (int)
    the amount of Wattage (float)
3 things it can do:
    write program
    create video
    edit photo
*/

struct CustomBuildPc
{
    // number of cpus
    int numOfCpus = 3;
    // amount of ram in gb
    int amountOfRamInGb = 32;
    // amount of HDD in gb
    int amountOfHddInGb = 2000;
    // number of OS
    int numberOfOs = 1;
    // amount of wattage
    int amountOfWattage = 600;

    struct Cpu
    {
        // clock spped of cpu
        float clockSpeedInGhz = 2.8f;
        // number of cpu cores
        int numCpuCore = 2;
        // number of physical cpu
        int numPhysicalCpus = 4;
        // brand of cpu
        std::string manufacturer = "Intel";
        // model name of cpu
        std::string model = "Xeon";

        void runProgram(int memoryUse, float wattageConsumption, float cpuTemp);
        float powerConsume(float timeCpuRunningInMinutes, int cpuUsage, bool multiThreadingOn = true); // return wattage cpu consumes
        float getTimeToCompile(float sizeOfFile, std::string compileError); // return compile time in minute
    };

    // write program
    void writeProgram(Cpu cpuA);
    // create video
    void createVideo(Cpu cpuB);
    // edit photo
    void editPhoto(std::string appToUse, float memoryUsage);

    Cpu cpuNotInUse;
};

/*
3) Photo Shoot
5 properties:
    number of cameras (int)
    the amount of memory card per shooting gb (int)
    number of hair make up artist (int)
    the amount of clothes needed (float)
    number of models to shoot per a day (int)
3 things it can do:
    make PR of company
    make a new style of fashion
    book rehearsal studios
*/

struct PhotoShoot
{
    // number of cameras
    int numCameras = 4;
    // amount of memory card per shooting in gb
    int amountOfMemoryCard = 512;
    // number of hair-make-up artist
    int numHariMakeUpArtists = 2;
    // amount of clothes needed
    float amountOfClothes = 25.0f;
    // number of models to shoot per day
    int numModel = 6;

    struct Camera
    {
        double shutterSpeed = 0.000125; // 1/8000 mm seconds
        bool isMirrorLess = true;
        std::string brand = "Nikon";
        std::string model = "Z9";
        std::string typeOfLens = "standard";

        void shootVideo();
        void changeLens(std::string nameOfLens);
        int takePhoto(); // return number of photos taken
    };    

    // make PR of company
    void makePr(std::string nameOfCompanies, std::string nameOfProduct);
    // make a new style of fashion
    void makeNewFashionStyle(Camera cameraA);
    // book rehearsal studios
    int bookStudio(int daysToShoot, int numOfCrews); // return dates of studio booked 
};

/*
4) Motorcycle Repair
5 properties:
    number of tools (int)
    the amount of engine oil (float)
    number of tires (int)
    number of chains (int)
    number of sprockets (int)
3 things it can do:
    clearn chain
    change tires
    repair carburetor
*/

struct MotorcycleRepair
{
    // number of tools
    int numTools = 48;
    // amount of engine oil
    float amountOfEnginOil = 25;
    // number of times
    int numTires = 2;
    // number of chains
    int numChains = 4;
    // number of sprockets
    int numSprockets = 2;

    // clean chain
    void cleanChain(float amountOfLube);
    // change tires
    int changeTires(float sizeOfTires, bool blockTire); // return how much it costs
    // repair carburetor
    void repairCarburetor(bool isStockCarburetor);
};

/*
5) Memory
5 properties:
    the amount of ram (int)
    number of apps running (int)
    number of memory bus speed (float)
    the amount of speed to read data (float)
    the amount of speed to write data (float)
3 things it can do:
    holds a bunch of apps running
    hispeed data transfer
    improve frame rate
*/

struct Memory
{
    // amount of ram
    int amountOfRam = 64;
    // number of apps running
    int numberOfAppsRunning = 15;
    // number of memory bus speed
    float memoryBusSpeed = 800;
    // amount of speed to read data
    float ramReadSpeed = 40; 
    // amount of speed to write data
    float ramWriteSpeed = 40;

    // holds a bunch of apps running
    float numAppRunning(float timeAppRunning, double maxMemoryUsed); // return how much memory available
    // hispeed data transfer
    void transferData(float peakTransferRate);
    // improve frame rate
    void improveFps(float fps, int refreshRate);
};

/*
6) Keyboard
5 properties:
    number of keys typed (int)
    the amount of key stroke (float)
    language of keyboard (std::string)
    the number of bluetooth channel (float)
    the number of usb ports (int)
3 things it can do: 
    type characters
    connect to usb 
    send key commands to the computer
*/

struct Keyboard
{
    // number of keys typed
    int numKeysTyped = 20;
    // amount of key stroke
    float distanceKeyTravel = 15.0f;
    // language of keyboard
    std::string keyLanguage = "US";
    // number of bluetooth channel
    float bluetoothChannel = 2.0f;
    // number of usb ports
    int numUsbPorts = 2;

    // type characters
    int typeCharacters(int wordTypedInMin); // return number of characters you typed
    // connect to usb
    void connectToUsb(int numPortsConnected);
    // send key commands to the computer
    void sendKeyCommands(int keyInput, std::string keyLanguage);
};

/*
7) Battery
5 properties:
    amount of battery power (float)
    hours to charge battery (float)
    number of battery (int)
    amount of peak wattage (float)
    size of battery cm (float)
3 things it can do:
    keep cpu running
    store electrical power
    charge other devices
*/

struct Battery
{
    // amount of battery power
    float batteryPower = 69.6f;
    // hours to charge the battery
    float chargeBattery = 1.5f;
    // number of battery
    int numBattery = 1;
    // amount of peak wattage
    float peakWattage = 96.0f;
    // size of battery 
    float sizeOfBattery = 1400;

    // keep cpu running
    void keepCpuRunning(float cpuAveragePowerConsumption, float cpuAveragePower);
    // store electriacl power
    float storeElectricalPower(float chargeBattery, float currentWattsInUse); // return amount of battery power left
    // charge other devices
    int chargeOtherDevices(int numPortsConnected, float powerDrawn); // return amount of power to charge other devices left
};

/*
8) Trackpad
5 properties:
    depth of track pad mm (int)
    width of track pad mm (int)
    sensitivity of trackpad (double)
    cursor acceralators (float)
    number of conductors (int)
3 things it can do:
    detect movements of finger tip
    detect positions 
    detect right click or left click
*/
struct Trackpad
{
    // depth of trackpad mm
    int depthOfTrackpad = 1149;
    // width of trackpad mm 
    int widthOfTrackpad = 1600;
    // sensitivity of trackpad
    double trackpadSensitivity = 5.00; 
    // cursor accrelators
    float cursorAcceleration = 2.0f;
    // number of conductors
    int numConductors = 2;

    // detect movements of finger tip
    void detectFingerMovement(float xPosition, float yPosition, bool isFingerOn = false);
    // detect positions
    float detectPositions(int numFingerTouched, bool isFingerMoved); // return x, y positions 
    // detect right click or left click
    void detectClick(float xPositionClicked, float yPositionClicked);
};

/*
9) SSD
5 properties:
    amount of SSD gb (int)
    the amoutn of speed of data transfer (float)
    brand (std::string)
    number of SSD (int)
    type of connection (std::string)
3 things it can do:
    read data
    write data
    install app
*/
struct SSD
{
    // amount of SSD in gb
    int sizeOfSsd = 512;
    // amount of speed of data transfer
    float dataTransferSpeed = 100; // mb/second
    // brand
    std::string brand = "Western Digital";
    // number of SSD
    int numOfSsd = 2;
    // type on connection
    std::string connectionType = "NVMe";

    // read data
    float readData(float sizeOfFile); // return speed of reading data
    // write data
    float writeData(float sizeOfFile); // return speed of wrting data
    // install app
    void installApp(float sizeOfAvailableSpace, float sizeOfApp);
};

/*
10) Laptop
5 properties:
    Memory
    Keyboard
    Battery
    Trackpad
    SSD
3 things it can do:
    Run a program
    Display fonts
    Calculate algorithm
 */

struct Laptop
{
    Memory samsung;
    Keyboard currentKeyboardLayout;
    Battery batteryChargeCycleCount;
    Trackpad externalTrackpadIsConnected;
    SSD Toshiba;

    // run a program
    int runProgram(int numAppsInstalled, float maxMemoryAppUse); // return number of apps running
    // Display fonts
    void displayFonts(std::string fontName);
    // Calculate algorithm
    void calculateAlgorithm(bool isWrittenInCpp);
};


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
