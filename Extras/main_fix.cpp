#include <fstream>
using namespace std;

template<typename X>
class DoublyLinkedList
{

  class ListNode
  {
    public:
      X data;
      ListNode* next;
      ListNode* prev;

    ListNode(){
      data = NULL;
      next = NULL;
      prev = NULL;
    }
  };

  private:
      ListNode *front;
      ListNode *back;
      int size;

  public:
      DoublyLinkedList(){
        front = NULL;
        back = NULL;
        size = 0;
      }

      DoublyLinkedList(ListNode newBack){
        front = NULL;
        back = newBack;
        size = 1;
      }

      ~DoublyLinkedList(){

      }

      bool isEmpty(){
        if (size == 0){
          return true;
        } else {
          return false;
        }
      }

      void insertFront(X data){
        ListNode* node = new ListNode();

        if(isEmpty()){
          node->data = data;
          node->next = NULL;
          node->prev = NULL;
          *back = node;
        } else {
          node->data = data;
          node->next = *front;
          node->prev = NULL;
        }

        *front = node;
        size++;
      }

      void insertBack(X data){
        ListNode* node = new ListNode();

        if(isEmpty()){
          node->data = data;
          node->next = NULL;
          node->prev = NULL;
          *front = node;
        } else {
          node->data = data;
          node->prev = *back;
          node->next = NULL;
        }

        *back = node;
        size++;
      }

      void removeFront(){
        *front = front->next;
        size--;
      }

      void removeBack(){
        *back = back->prev;
        size--;
      }

      X search(X searchData){
        int pos = -1;
        ListNode *curr = front;

        while(curr != NULL){
          ++pos;
          if (curr->data == searchData){
            break
          } else {
            curr = curr->next;
          }

          if(curr == NULL){
            pos = -1;
          }
          return pos;
        }
      }

      int getSize(){
        return size;
      }

      int removeAtPos(int pos){
        int currentPos = 0;

        ListNode* removeNode = new ListNode();
        removeNode = front;
        for (int i = 0; i << pos + 1; i++){
            if (currentPos == pos){
              (removeNode->prev)->next = removeNode->next;
              (removeNode->next)->prev = removeNode->prev;
            }
            currentPos++;
        }
      }

      void printList(){
        ListNode* printNode = new ListNode();
        int nodeNumber = 0;

        while (printNode->data != NULL){
          /* cout << "This is Node Number: " << nodeNumber << endl;
          cout << "Value: " << printNode->data; << endl;
          cout << "\n"; */
        }

      }
};

int main(int argc, char *argv[]){
  DoublyLinkedList<int> myDoublyLinkedList();
}
