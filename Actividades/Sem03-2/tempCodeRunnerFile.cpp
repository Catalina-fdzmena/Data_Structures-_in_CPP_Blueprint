//Uncomment in case it's necesary 
/* 
        if((list[mid]!=list[mid-1]) && (list[mid]!=list[mid+1])){
            cout<<list[mid]<<" "<<cont<<endl;
            break;
        } else if (mid%2==0){
            if (list[mid]==list[mid+1]){
                left = mid+1;
            } else if (list[mid]==list[mid-1]){
                right = mid-1;
            } else {
                cout<<list[mid]<<" "<<cont<<endl;
                break;
            }
        }else{
            if (list[mid]==list[mid+1]){
                right = mid-1;
            } else if (list[mid]==list[mid-1]){
                left = mid+1;
            } else {
                cout<<list[mid]<<" "<<cont<<endl;
                break;
            }
        }
        mid = (right+left)/2;
        cont++;
    }
    if(valid==false)
        cout << "CRITICAL ERROR " << endl;
}
//---


//En el main realizamos la respectiva únificación de las secciones de nuestra función para mostrar 
int main(){
    
    //Pedir archivo de prueba
    ifstream archivo;
    string nombre_archivo;  //Se crea string para pedir nombre del archivo 
    cout << "Call out the document you would like to read (name.in): ";
    cin >> nombre_archivo;
    archivo.open(nombre_archivo);

    //Crear vector de renglones 
    vector<string> renglones;
    int n; //Numero de renglones
    archivo >> n;
    string renglon;
    for(int i=0; i < n ; i++){
        archivo >> renglon;
        renglones.push_back(renglon);
    }
    archivo.close();
    //Una vez realizada lectura se elabora búsqueda binaria 
    
    for(int i=0; i < n ; i++){
        //Desarrollar vector para organizar cada uno de los caracteres y ordenarlos
        vector<char> caracteres(renglones[i].begin(), renglones[i].end());
        busquedaSecuencial(caracteres);
        sort(caracteres.begin(), caracteres.end());
        busquedaBinaria(caracteres);
    }  */