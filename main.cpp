/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

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
