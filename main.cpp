#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<typename X>
struct ListNode {
  X data;
  ListNode *next;
  ListNode *prev;
};

template<typename X>
class DoublyLinkedList {
  private:
    ListNode<X> *front;
    ListNode<X> *back;
    int size;

  public:
    DoublyLinkedList(){
      front = NULL;
      back = NULL;
      size = 0;
    }

    DoublyLinkedList(ListNode<X> *node){
      front = node;
      back = node;
      size = 1;
    }

    ~DoublyLinkedList(){
      //implement later
    }

    bool isEmpty(){
      if (size == 0){
        return true;
      } else {
        return false;
      }
    }

    X getMedian(){
      ListNode<X>* testNode;
      testNode = front;
      int medianPos = size / 2;
      if (size == 1){
        return front->data;
      } else if (size == 0){
        return -1;
      } else {
        for (int i = 0; i < medianPos; ++i){
          testNode->next;
        }
        return testNode->data;
      }
    }

    ListNode<X>* getBack(){
      return back;
    }

    ListNode<X>* getFront(){
      return front;
    }

    void insertFront(X data){
      ListNode<X>* insertNode = new ListNode<X>;

      insertNode->data = data;

      if(isEmpty() == true){
        front = insertNode;
        back = insertNode;
      } else {
        front->prev = insertNode;
        insertNode->next = front;
        front = insertNode;
      }

      size++;
    }

    void insertBack(X data){
      ListNode<X>* insertNode = new ListNode<X>;

      insertNode->data = data;

      if(isEmpty() == true){
        front = insertNode;
        back = insertNode;
      } else {
        back->next = insertNode;
        insertNode->prev = back;
        back = insertNode;
      }

      size++;
    }

    ListNode<X>* removeFront(){
      ListNode<X>* removeNode;
      removeNode = front;

      if (size == 1){
        front = NULL;
        back = NULL;
      } else {
        front = front->next;
        front->prev = NULL;
        removeNode->next = NULL;
      }
      size--;
      return removeNode;
    }

    ListNode<X>* removeBack(){
      ListNode<X>* removeNode;
      removeNode = back;

      if (size == 1){
        front = NULL;
        back = NULL;
      } else {
        back = back->prev;
        back->next = NULL;
        removeNode->prev = NULL;
      }

      size--;
      return removeNode;
    }

    int search(X searchData){
      bool search = true;

      ListNode<X>* searchNode = new ListNode<X>;
      searchNode = front;
      int searchIndex = -1;

      while(search == true){
        searchIndex++;
        if (searchNode->data == searchData){
          return searchIndex;
          search = false;
        }
        searchNode = searchNode->next;
      }

      searchNode = searchNode->next;
    }

    int getSize(){
      return size;
    }

    X removeAtPos(int pos){
      ListNode<X>* removeNode;
      ListNode<X>* leftNode;
      ListNode<X>* rightNode;
      removeNode = front;

      X returnData;

      if (size == 0){
        cout << "Cannot remove, the list is empty!" << endl;
        return -1;
      } else if (pos == 0){
        returnData = removeNode->data;
        removeFront();
      } else {
        for (int i = 0; i < pos; i++){
          removeNode = removeNode->next;
        }
        leftNode = removeNode->prev;
        rightNode = removeNode->next;
        if(leftNode != NULL){
          leftNode->next = rightNode;
        } else {
          rightNode->prev = NULL;
        }
        if (rightNode != NULL){
          rightNode->prev = leftNode;
        } else {
          leftNode->next = NULL;
        }
        returnData = removeNode->data;
        delete removeNode;
        size--;
      }
      return returnData;
    }

    void printList(){
      ListNode<X>* printNode = new ListNode<X>;
      printNode = front;

      cout << "\n";
      for (int i = 0; i < size; i++){
        cout << "This is Node Number: " << i << endl;
        cout << "Value: " << printNode->data << endl;
        cout << "\n";
        printNode = printNode->next;
      }
      delete printNode;
    }

};

template<typename X>
class GenQueue {
  private:
    DoublyLinkedList<X>* myList;

  public:
    GenQueue(){
      DoublyLinkedList<X>* myConstructorList = new DoublyLinkedList<X>;
      myList = myConstructorList;
    }

    bool isEmpty(){
      return myList->isEmpty();
    }

    int getSize(){
      return myList->getSize();
    }

    X getFront(){
      X data;
      data = (myList->front)->data;
      return data;
    }

    ListNode<X>* getFrontNode(){
      ListNode<X>* frontPointer;
      frontPointer = myList->getFront();
    }

    X getBack(){
      X data;
      data = myList->getBack()->data;
      //data = (myList->back)->data;
      return data;
    }

    void push(X data){
      myList->insertFront(data);
    }

    X pop(){
      X data;
      data = getBack();
      myList->removeBack();
      return data;
    }

    void printQueue(){
      myList.printList();
    }
};

class student{

  private:
    int timeNeeded;
    int timeRegistrar;
    int timeWaiting;
    bool finished;

  public:
    student(){
      timeNeeded = 0;
      timeRegistrar = 0;
      timeWaiting = 0;
      finished = false;
    }

    student(int needed){
      timeNeeded = needed;
      timeRegistrar = 0;
      timeWaiting = 0;
      finished = false;
    }

    void wait(){
      timeWaiting++;
    }

    void atWindow(){
      timeRegistrar++;
    }

    bool checkNeed(){
      if (timeNeeded == timeRegistrar){
        finished = true;
      } else {
        finished = false;
      }
      return finished;
    }

    int getNeed(){
      return timeNeeded;
    }

    int getWait(){
      return timeWaiting;
    }

    int getRegistrar(){
      return timeRegistrar;
    }

    void setNeed(int newNeed){
      timeNeeded = newNeed;
    }

    void printStudent(){
      cout << "Time Needed: " << timeNeeded << endl;
      cout << "Time with registrar: " << timeRegistrar << endl;
      cout << "Time Waiting: " << timeWaiting << endl;
    }

};

class registrar{

  private:
    int waitingOpen;
    student currentStudent;
    bool open;

  public:
      registrar(){
        waitingOpen = 0;
        open = true;
      }

      void working(){
        currentStudent.atWindow();
      }

      student finishStudent(){
        open = true;
        return currentStudent;
      }

      void insertStudent(student newStudent){
        currentStudent = newStudent;
        open = false;
      }

      void wait(){
        waitingOpen++;
      }

      student returnStudent(){
        return currentStudent;
      }

      bool getOpen(){
        return open;
      }

      int getIdleTime(){
        return waitingOpen;
      }

      bool checkStudentNeed(){
        if (currentStudent.checkNeed() == true){
          return true;
        } else {
          return false;
        }
      }
};

class studentWave{
  private:
    int numberOfStudents;
    student *waveArray;
    int waveTime;

  public:
      studentWave(){
        numberOfStudents = 0;
      }

      studentWave(int passTime){
        waveTime = passTime;
        numberOfStudents = 0;
      }

      void setStudentNumbers(int amount){
        numberOfStudents = amount;
        waveArray = new student[numberOfStudents];
      }

      void setStudentNeeds(int pos, int timeNeeded){
        waveArray[pos].setNeed(timeNeeded);
      }

      void setStudent(int pos, student passStudent){
        waveArray[pos] = passStudent;
      }

      void setTime(int passTime){
        waveTime = passTime;
      }

      int getTime(){
        return waveTime;
      }

      int getStudentNumbers(){
        return numberOfStudents;
      }

      student getStudent(int pos){
        return waveArray[pos];
      }

      void printWave(){
        for (int i = 0; i < numberOfStudents; i++){
          student printStudent;
          printStudent = waveArray[i];
          printStudent.printStudent();
        }
        cout << "Wave Time: " << waveTime << endl;
      }

};

int main(int argc, char *argv[] ){
  cout << "\n===============================================================\n";
  cout << "            Welcome to Michael's Magical Registrar!";
  cout << "\n===============================================================\n";
  cout << "\n";

  cout << "Please enter the name of your registrar line file: ";
  string fileName = "";
  getline(cin, fileName);
  string registrarInfo;

  ifstream registrarCode(fileName);

  cout << "\n";
  cout << "File contents:" << endl;
  while(getline(registrarCode, registrarInfo)){
    cout << registrarInfo << endl;
  }
  registrarCode.clear(); //resets the input text file
  registrarCode.seekg(0, ios::beg); //resets the input text file
  cout << "\n";

  int windows = 0;
  registrar* registrarOffice[windows]; // creates an array of registrars
  while(getline(registrarCode, registrarInfo)){
      windows = stoi(registrarInfo);
      for (int i = 0; i < windows; i++){
        registrar* regWindow = new registrar();
        registrarOffice[i] = regWindow;
      }
      break;
  }
  cout << "Registrar Windows: " << windows << endl;
  cout << "\n";

  DoublyLinkedList<studentWave> myWaveList; //creates line that the waves of students will be in
  DoublyLinkedList<int> waitTimeList;
  studentWave genWave; //this is the structure for the student wave
  int currentLineNumber = 0;
  bool waveTimeBool = true;
  bool wavePopulationSetBool = false;
  bool setStudents = false;
  bool registrarWorking = false;
  bool noOpenRegistrars = false;
  int waveNumber = 1;
  int waveTime = 0;
  int incomingStudents = 0;
  int currentWaveStudent = 1;
  while(getline(registrarCode, registrarInfo)){ //This code creates the waves that will be checked by the clock
    if (waveTimeBool == true){
      cout << "Wave Number: " << waveNumber << endl;
      waveNumber++;
      waveTime = stoi(registrarInfo);
      cout << "Wave Time: " << waveTime << endl;
      wavePopulationSetBool = true;
      waveTimeBool = false;
      genWave.setTime(waveTime);
    } else if (wavePopulationSetBool == true){
      incomingStudents = stoi(registrarInfo);
      cout << "Wave population: " << incomingStudents << endl;
      wavePopulationSetBool = false;
      setStudents = true;
      genWave.setStudentNumbers(incomingStudents);
    } else if (setStudents == true && incomingStudents > 0){
      int neededTime = stoi(registrarInfo);
      student visitor;
      visitor.setNeed(neededTime);
      genWave.setStudent(incomingStudents - 1, visitor);
      cout << "Student: " << currentWaveStudent << " | Time Needed: " << neededTime << endl;
      currentWaveStudent++;
      incomingStudents--;
      if (incomingStudents == 0){
        setStudents = false;
        waveTimeBool = true;
        cout << "\n";
        myWaveList.insertFront(genWave);
        studentWave cleanWave;
        genWave = cleanWave;
      }
    }
  }

    int totalWaitTime = 0;
    int meanStudentWaitTime = 0;
    int medianStudentWaitTime = 0;
    int longestStudentWaitTime = 0;
    int studentsWaitingOverTenMinutes = 0;
    int meanWindowIdleTime = 0;
    int longestWindowIdleTime = 0;
    int numberOfWindowsIdleOverTenMinutes = 0;

    int passingNumberOfStudents = 0;

    int clockTick = 0;
    GenQueue<student>* myLine = new GenQueue<student>; //Creates line that students will be standing in
    int wavePos = 0;
    ListNode<studentWave>* testWave = myWaveList.getFront();
    bool foundTick = false;
    studentWave insertWave;

    while(myWaveList.getSize() != 0 || myLine->isEmpty() == false || registrarWorking == true){ //This runs the clock ticks
      registrarWorking = false;
      testWave = myWaveList.getFront();
      foundTick = false;
      cout << "\n";
      cout << "Time: " << clockTick << endl;
      wavePos = 0;

      while (testWave != NULL && foundTick == false){ //This checks at the beggining of each minute for a wave to be used
        int waveTick = (testWave->data).getTime();
        //cout << "Wave Tick(s): " << waveTick << endl;
        if(waveTick == clockTick){
          insertWave = testWave->data;
          foundTick = true;
          myWaveList.removeAtPos(wavePos);
        }
        testWave = testWave->next;
        wavePos++;
      }

      if (foundTick == true){ //if a wave is found this code puts the students into the line
        //cout << "\n";
        cout << "Students Lining Up: " << insertWave.getStudentNumbers() << endl;
        //cout << "\n";
        for (int i = 0; i < insertWave.getStudentNumbers(); i++){
          student pushStudent;
          pushStudent = insertWave.getStudent(i);
          myLine->push(pushStudent);
        }
      }

      if (myLine->getSize() != 0){//if a registrar window is open this code puts a student in line into a registrar window
        for (int i = 0; i < windows; i++){
          if (registrarOffice[i]->getOpen() == true && myLine->isEmpty() == false){
            registrarOffice[i]->insertStudent(myLine->pop());
            cout << "student inserted into registrar!" << endl;
            passingNumberOfStudents++;
          }
        }
      }

      for (int i = 0; i < windows; i++){
        if (registrarOffice[i]->getOpen() == true){
          registrarOffice[i]->wait();
        }
      }

      for (int i = 0; i < windows; i++){
        if (registrarOffice[i]->getOpen() == false){
          registrarOffice[i]->working();
          registrarWorking = true;
          cout << "Registrar " << i << " is working" << endl;
          if (registrarOffice[i]->checkStudentNeed() == true){
            int currentStudentWait = (registrarOffice[i]->returnStudent()).getWait();
            totalWaitTime = totalWaitTime + currentStudentWait;
            if(currentStudentWait > longestStudentWaitTime){
              longestStudentWaitTime = currentStudentWait;
            }
            if (currentStudentWait > 10){
              studentsWaitingOverTenMinutes++;
            }
            waitTimeList.insertFront(currentStudentWait);
            registrarOffice[i]->finishStudent();
            cout << "Registrar " << i << " Finished with Student!" << endl;
          }
        }
      }

      ListNode<student>* frontPointer = myLine->getFrontNode();
      for (int i = 0; i < myLine->getSize(); i++){
        (frontPointer->data).wait();
        frontPointer = frontPointer->next;
      }


      clockTick++;
    }

    if (totalWaitTime == 0){ //gets mean wait time
      meanStudentWaitTime = 0;
    } else {
      meanStudentWaitTime = totalWaitTime / passingNumberOfStudents;
    }

    medianStudentWaitTime = waitTimeList.getMedian(); //gets median wait time

    int totalIdleWindowtime = 0;
    for (int i = 0; i < windows; i++){ // gets total window idle time
      int currentWindowIdle = registrarOffice[i]->getIdleTime();
      totalIdleWindowtime += currentWindowIdle;
      if (currentWindowIdle > longestWindowIdleTime){
        longestWindowIdleTime = currentWindowIdle;
      }
      if (currentWindowIdle > 10){
        numberOfWindowsIdleOverTenMinutes++;
      }
    }
    meanWindowIdleTime = totalIdleWindowtime / windows;

    cout << "\n";
    cout << "==========================" << endl;
    cout << "         Statistics       " << endl;
    cout << "==========================" << endl;
    cout << "\n";

    cout << "Number of total students helped: " << passingNumberOfStudents << endl;
    cout << "Total time spent waiting: " << totalWaitTime << endl;
    cout << "Total idle window time: " << totalIdleWindowtime << endl;
    cout << "\n";

    cout << "Average time spent waiting: " << meanStudentWaitTime << endl;
    cout << "Median time spent waiting: " << medianStudentWaitTime << endl;
    cout << "Longest Student Wait Time: " << longestStudentWaitTime << endl;
    cout << "The number of students waiting over 10 minutes: " << studentsWaitingOverTenMinutes << endl;
    cout << "The mean window idle time: " << meanWindowIdleTime << endl;
    cout << "Longest idle window time: " << longestWindowIdleTime << endl;
    cout << "The number of windows idle over ten minutes: " << numberOfWindowsIdleOverTenMinutes << endl;
    cout << "\n";

}
