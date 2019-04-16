#include <iostream>
using namespace std ;

struct Contact
{
    char nama[10] ;
    char phone[10] ;
    Contact* next ;
};

struct Index {
    char index ;
    Index* next ;
    Contact* nextContact ;
} ;

typedef Index* list ;
typedef Index* pointerIndex ;
typedef Contact* pointerContact ;

void CreateListIndex (list& first) {
    first = NULL  ;
}


void CreateElementIndex (list& first, pointerIndex& pBaru) {
    pBaru = new Index ;
    cout << "Index ? " ; cin >> pBaru->index ;
    pBaru->next = NULL ;
    pBaru->nextContact = NULL ;
}

void InsertElemenIndex (list& first, pointerIndex& pBaru) {
    if (first == NULL){
        first = pBaru ;
    } 
    else {
        pBaru->next = first;
        first = pBaru ;
    }
}

void CreateElemenContact (list& first,pointerContact& pBaru ) {
    pBaru = new Contact ;
    cout << "Nama ? " ; cin >> pBaru->nama ;
    cout << "Nomor ? " ; cin >> pBaru->phone ;
    pBaru->next = NULL ;
}

void LinearSearch (list& first, pointerIndex& pCari, char key, int& status){
    status = 0; 
    pCari = first ;
    while (pCari != NULL && status == 0)
    {
        if (key == pCari->index) {
            status = 1 ;
        }
        else {
            pCari = pCari->next ;
        }
    }
    
}

void InsertElemenContact (list& first,pointerContact& pBaru, char key) {
    pointerIndex  pIndex;
    int ketemu ;
    cout << "Masukkan Index yang dicari : " ; cin >> key ;
    LinearSearch(first,pIndex,key,ketemu) ;
    if (ketemu) {
        cout << "DITEMUKAN\n" ;
        if (pIndex->nextContact == NULL) {
            pIndex->nextContact = pBaru ;
        }
        else {
            pBaru->next = pIndex->nextContact ;
            pIndex->nextContact = pBaru ;
        }
    }
}

void showIndex (list& first) {
    pointerIndex pBantu ;
    pBantu = first ;
    while (pBantu != NULL) {
        cout << pBantu->index << " " ;
        pBantu = pBantu->next ;
    }
}

void showContact (list& first) {
    pointerContact pBantu ;
    pointerIndex pI ;
    char key ; int x ;

    cout << "INDEX BERAPA ? " ; cin >> key ;
    LinearSearch(first,pI,key,x) ;    
    if (x) {
        pBantu = pI->nextContact ;
        while (pBantu != NULL)
        {
            cout << pBantu->nama << " " << pBantu->phone << endl;
            pBantu = pBantu->next ;
        }   
    } 
}

void DeleteFirstIndex (list& first, pointerIndex& pHapus) {
    if (first->next == NULL) {
        first = NULL ;
    }
    else {
        pHapus = first ;
        first = first->next ;
        pHapus->next = NULL ;
    }
}

void DeleteFirstContact(list& first , pointerContact& pHapus) {
    pointerIndex pIndex ;
    int x ;char key ;
    cout << "INDEX MANA ? "; cin >> key ;
    LinearSearch(first,pIndex,key,x) ;

    if (x) {
        if (pIndex->nextContact == NULL)
        {
            cout << "Kontak kososng" ;
        }
        else if (pIndex->nextContact->next == NULL)
        {
            pHapus = pIndex->nextContact ;
            pIndex->nextContact = NULL ;
            cout << "Sudah\n" ;
        }
        else {
            pHapus = pIndex->nextContact ;
            pIndex->nextContact = pIndex->nextContact->next ;
            pHapus->next = NULL ;  
        }
    }    
}


int main() {
    list first ;
    pointerIndex pI ;
    pointerContact pC ;
    char key ;

    CreateListIndex(first) ;
    int a ;
    cout << "1. Create Index\n" ;
    cout << "2. Create Contact\n" ;
    cout << "3. Delete Index\n" ;
    cout << "4. Delete Contact\n" ;
    cout << "5. Show Index\n" ;
    cout << ". Show Contact\n" ;
    cout << "99. exit\n" ;

    do {
        cout << " :: " ; cin >> a ;
        switch (a) {
            case 1 :
                CreateElementIndex (first,pI) ;
                InsertElemenIndex (first,pI) ;
                break;
            case 2 :
                CreateElemenContact(first,pC) ;
                InsertElemenContact(first,pC,key) ;
                break ;
            case 3 :
                DeleteFirstIndex(first,pI) ;
                cout << "==DELETED==\n" ;
                break ;
            case 4 :
                DeleteFirstContact (first,pC) ;
                cout << "==DELETED==\n" ;
            case 5 :
                showIndex(first) ;
                cout << endl ;
                break ;
            case 99 :
                break ;
            default:
                showContact(first) ;
                break;
        }
    } while (a != 99) ;
}
