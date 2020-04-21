/*
 while(getline(registrarCode, registrarInfo)){
   if (currentLineNumber == 0){
     //do nothing
   } else if (waveTimeSet == false){
     genWave.setTime(stoi(registrarInfo)); //sets time at which wave arrives
     waveTimeSet = true;
   } else if (waveTimeSet == true && fillingWave == false){
     fillingWave = true;
     incomingStudents = stoi(registrarInfo);
     genWave.setStudentNumbers(stoi(registrarInfo)); // create student array in wave object
   } else if (waveTimeSet == true && fillingWave == true){
       if(incomingStudents == 0){
         waveTimeSet = false;
         fillingWave = false;
         myWaveList.insertFront(genWave);
       } else {
         student newStudent = student(stoi(registrarInfo);
         genWave.setStudent(countingStudents, newStudent);
         countingStudents++;
         incomingStudents--;
       }
   }



   currentLineNumber++;




 } */



   /*else if (currentLineNumber == 1){
     waveTime = stoi(registrarInfo); // gets the time when
   } else if (currentLineNumber == 2){
     fillingWave = true;
     waveStudents = stoi(registrarInfo);
     stagingNumber = currentLineNumber;
   } else if ( currentLineNumber < (stagingNumber + waveStudents) ){

   }
   currentLineNumber++;
 } */

 /*studentWave genWave;
 GenQueue<studentWave> myNewWaveList;
 myNewWaveList.insertFront(genWave); */

 //First Line(5) - Number of Windows open

 //Second Line(1) - Time when students arrive
 //Third Line(2) - Number of Students arriving
 //Fourth Line(5) - Amount of Time 1st student needs
 //Fifth Line(10) - Amount of Time 2nd student needs

 //Sixth Line(3) - When next student group arrives
 //Seventh Line - Number of Students arriving
 //Eighth Line - Amount of time 1st student needs




 while (testWave != NULL){
   int waveTick = (testWave->data).getTime();
   if (waveTime == clockTick){
     cout << "Tick Tock" << endl;
   }
   testWave = testWave->next;
 }

 cout << "Time: " << clockTick << endl;
 clockTick++;


 /*ListNode<studentWave>* testWave = myWaveList.getFront();
 studentWave newTestWave = (testWave->next)->data;
 newTestWave.printWave();

 ListNode<studentWave>* testWave2 = myWaveList.getBack();
 studentWave newTestWave2 = (testWave2->prev)->data;
 newTestWave2.printWave();

 cout << "Size of the wave linked list: " << myWaveList.getSize() << endl;
 cout << "\n";
 cout << "Removing Front..." << endl;
 myWaveList.removeBack();
 cout << "Size of the wave linked list: " << myWaveList.getSize() << endl;
 cout << "\n";

 testWave = myWaveList.getFront();
 cout << "Front acquired" << endl;
 if (testWave == NULL){
   cout << "The front was NULL" << endl;
 } else {
   newTestWave = testWave->data;
   newTestWave.printWave();
 }

 cout << "\n";
 cout << "Removing Front..." << endl;
 myWaveList.removeFront();
 cout << "Size of the wave linked list: " << myWaveList.getSize() << endl;
 cout << "\n";*/

clockTick < 11


|| clockTick < 30
