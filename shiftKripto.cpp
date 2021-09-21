#include <iostream>
using namespace std;

int main(){
    int choice;
    char status;
    do{
        cout << "1.Enkripsi" << endl << "2. Dekripsi" << " Masukan pilihan (1,2): ";
        cin >> choice;
        cin.ignore();

        if(choice == 1){
            // enkripsi
            string msg;
            cout << " Pesan menggunakan huruf " << endl;
            cout << " Masukan pesan : ";
            getline(cin,msg);

            int key;
            cout << " Masukan kunci (0-25): ";
            cin>> key;
            cin.ignore();

            string encryptedText = msg;
            for (int i = 0; i < msg.size(); i++ ){
                if (msg[i] == 32){
                    continue; //32 adalah angka bilangan ASCII di mana itu adalah karakter space sehingga cukup diabaikan 
                }else{
                    if ((msg[i] + key) > 122){
                        //After lowercase z move back to a, z's ASCII is 122
                        int temp = (msg[i] + key) -122;
                        encryptedText[i] = 96 + temp;
                    }else if ( msg[i] + key > 90 && msg[i] <= 96){
                        //after uppercase Z move back to A, 90 is Z's Ascii
                        int temp = (msg[i] + key ) - 90;
                        encryptedText[i] = 64 + temp;
                    }else{
                        //Mempertimbangkan huruf kapital atau huruf kecil
                        encryptedText[i] += key;
                    }
                } // if
            } // for
            cout << "Pesan terenkripsi : " << encryptedText << endl;
        } else if (choice == 2){
            // dekripsi 

            string encpMsg;
            cout << " Gunakan huruf untuk masukan pesan " << endl;
            cout << " Masukan pesan yang terenkripsi : " << endl;
            getline(cin, encpMsg);

            int dcyptKey;
            cout << " Enter key (0-25): ";
            cin >> dcyptKey;
            cin.ignore();

            string decryptedText = encpMsg;
            for (int i = 0; i < encpMsg.size(); i++){
                if(encpMsg[i]==32){
                    continue; // Mengabaikan spasi
                }else {
                    if ((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    }else if((encpMsg[i] - dcyptKey) < 65){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    }else{
                        decryptedText[i] = encpMsg[i] - dcyptKey;
                    }
                }
            }

            cout << "Pesan yang terdeskripsi: " << decryptedText << endl;
        }else{
            cout << "Invalid choice";
        }
        cout<<"Lanjutkan program [Y/N]? " << endl;
        cin>> status;   
    }while(status=='Y'||status=='y');
    cout<<"Keluar program"<<endl;
    return 0;   
}