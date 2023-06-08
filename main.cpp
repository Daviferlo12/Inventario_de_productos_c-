#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<algorithm>

using namespace std;


//Declaracion de la estructura Productos
struct Productos{
  int id;
  string nombre;
  string tipo;
  string laboratorio;
  float precio;
  string descuento;
  double descuento_num;
  int stock;
};

// Primer Ciudad
vector<Productos> san_vicente;
vector<Productos> la_y;

//Segunda Ciudad
vector<Productos> medallo;
vector<Productos> la_nea;

//Tercer Ciudad
vector<Productos> la_costa;
vector<Productos> la_rebaja;



// FUNCIONES PARA CREAR INVENTARIO
Productos add_inventory(int id, string nombre, string tipo, string laboratorio,float precio, string descuento, double descuento_num, int stock){

  Productos new_product;
  
  new_product.id = id;
  new_product.nombre = nombre;
  new_product.tipo = tipo;
  new_product.laboratorio = laboratorio;
  new_product.precio = precio; 
  new_product.descuento = descuento;
  new_product.descuento_num = descuento_num;
  new_product.stock = stock;

  return new_product;
  
}


// FUNCION PARA MOSTRAR PRODUCTOS
void show_products(vector<Productos> productos){

  size_t ancho_col_nombre = 0;
  size_t ancho_col_tipo = 0;
  size_t ancho_col_laboratorio = 0;

  for(int j = 0;j < productos.size();j++){
    ancho_col_nombre = max(ancho_col_nombre, productos[j].nombre.length());
    ancho_col_tipo = max(ancho_col_tipo, productos[j].tipo.length());
    ancho_col_laboratorio = max(ancho_col_laboratorio, productos[j].laboratorio.length());
  }


  //CABECERA DE TABLA INVENTARIO
  cout << "\n -------------------------------------------------------------------------------------------------------------------\n";
  cout << "| ID | "<<
            setw(ancho_col_nombre) <<"NOMBRE |"<<
            setw(ancho_col_tipo + 5)<<"TIPO |"<< 
            setw(ancho_col_laboratorio + 5) <<"LABORATORIO |"<< 
            setw(20) <<"PRECIO |"<< 
            setw(10) <<"DESCUENTO |"<< 
            setw(10) <<"CANTIDAD |\n";
  cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
  for(int i = 0; i < productos.size(); i++) {

    //FILAS DE LA TABLA INVENTARIO
    cout << "\n| "<< productos[i].id << "   | " << 
                  setw(ancho_col_nombre) << productos[i].nombre << " |" << 
                  setw(ancho_col_tipo + 5) << productos[i].tipo<< " |" << 
                  setw(ancho_col_laboratorio + 5) << productos[i].laboratorio << " | " << 
                  setw(10) << productos[i].precio << " | " << 
                  setw(10) << productos[i].descuento << " | " <<
                  setw(10) <<productos[i].stock << " |\n";

  }
  
}

//ACTUALIZAR INVENTARIO
void update_stock(vector<Productos>& vector, int id, int cantidad) {
  for (int i = 0; i < vector.size(); i++) {
    if (vector[i].id == id) {
      vector[i].stock -= cantidad;
      break;
    }
  }
}


//VALIDAR SI EL PRODUCTO EXISTE
bool search_product(vector<Productos> vector, int id){
  for(int i = 0; i < vector.size(); i++){
    if(vector[i].id == id){
      return true;
      // break;
    }
  }
  return false;
}


//GENERAR FACTUDA DE PAGO
void generate_recipe(vector<Productos> vector, string nombre, int cedula){
    system("clear");
    cout << "FACTURA: \n";
  
    float sum = 0;
    
  for(int i = 0; i < vector.size(); i++){
      sum += vector[i].precio;
    }
    cout << "\n-----------------------------------------------------------------------------------------------------\n";
    cout << " NOMBRE: "<< nombre <<" | CEDULA: " << cedula <<" |\n";
    cout << "\n-----------------------------------------------------------------------------------------------------\n";
    show_products(vector);
    cout << "\n-----------------------------------------------------------------------------------------------------\n";
    cout << " TOTAL | "<< sum << " |\n";
    cout << "\n-----------------------------------------------------------------------------------------------------\n\n\n";

    cout << "[*] GRACIAS POR SU COMPRA.... \n";
    system("sleep 3s");
}




int main() {

  // FARMACIAS PRIMERA CIUDAD

    //Creacion inventario farmacia san_vicente
    san_vicente.push_back(add_inventory(1, "Acetaminofén 500 mg Frasco x 24 Tabletas", "Analgésico/antipiretico", " TECNOQUÍMICAS S.A. ", 20.95, "10%" ,0.90, 8));
    san_vicente.push_back(add_inventory(2, "Noxpirin Plus x 12 Cápsulas", "Antigripal","BAYER S.A. " , 14.95, "10%" ,0.90, 14));
    san_vicente.push_back(add_inventory(3, "Advil Gripa x 10 capsulas", "Analgésico", " Pfizer S.A.S. " , 16.95, "10%" ,0.90, 7));
    san_vicente.push_back(add_inventory(4, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 7.95, "10%",0.90, 3));
    san_vicente.push_back(add_inventory(5, "SAL DE FRUTAS LUA PLUS CAJA X 20 SOB", "Antiflatulento", " TECNOQUÍMICAS S.A. " , 54.9, "10%" , 0.90, 15));
    san_vicente.push_back(add_inventory(6, "Leche Magnesia MK Frasco x 120ml", "Antiácidos / Laxantes", " ASPEN COLOMBIANA SAS " , 8.35, "10%" ,0.90, 10));
    san_vicente.push_back(add_inventory(7, "Pedialyte Max Zinc Uva Frasco x 500 ml", "rehidratación ", " Abbott " , 6.5, "10%" ,0.90, 19));
    san_vicente.push_back(add_inventory(8, "Birm Inmunomodulador Frasco x 120 ml", "Fitoterapéutico" ," Green Terra Life " , 109.95, "10%" ,0.90, 5));
    san_vicente.push_back(add_inventory(9, "Panotil B Frasco x 8 ml", "Antiinflamatorio" ," Zambon colombia " , 19.95, "10%" ,0.90, 6));
    san_vicente.push_back(add_inventory(10, "Digestar Fibra Natural Polvo Tarro X 300Gr", "Laxante" ," NATURAL FRESHLY " , 64.9, "10%" ,0.80, 12));
  
    //Creacion Inventario farmacia LA Y
    la_y.push_back(add_inventory(1, "Viagra Sildenafil 50 mg Caja x 4 Tabletas", "Viagra ","Pfizer s.a. " , 45.1, "10%" ,0.90, 14));
    la_y.push_back(add_inventory(2, "Shampoo Tío Nacho x 1 lt", "Antiséptico, Antiseborreico ","Tío Nacho " , 43.45, "10%" ,0.90, 13));
    la_y.push_back(add_inventory(3, "Noraver Garganta Menta Caja x 12 Tabletas", "Antiséptico y anestésico","TECNOQUIMICAS S.A. " , 20.5, "10%" ,0.90, 9));
    la_y.push_back(add_inventory(4, "Alcohol Mk Antiseptico Uso Externo x 700 ml", "Antiséptico ","TECNOQUIMICAS S.A. " , 8.95, "10%" ,0.90, 11));
    la_y.push_back(add_inventory(5, "Cura Cure Band Standard Translucidas x 30 und", "Adhesivos y botiquín ","Cure band " , 4.5, "10%" ,0.90, 17));
    la_y.push_back(add_inventory(6, "Advil Gripa x 10 capsulas", "Analgesico", " Pfizer S.A.S. " , 16.95, "10%" ,0.90, 2));
    la_y.push_back(add_inventory(7, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 7.95, "10%" ,0.90, 20));
    la_y.push_back(add_inventory(8, "Leche Magnesia MK Frasco x 120ml", "Antiacidos / Laxantes", " ASPEN COLOMBIANA SAS " , 8.35, "10%" ,0.90, 13));
    la_y.push_back(add_inventory(9, "Pedialyte Max Zinc Uva Frasco x 500 ml", "rehidratacion ", " Abbott " , 6.5, "10%" ,0.90, 18));
    la_y.push_back(add_inventory(10, "SAL DE FRUTAS LUA PLUS CAJA X 20 SOB", "Antiflatulento", " TECNOQUIMICAS S.A. " , 54.9, "10%" ,0.90, 10));
  
  
  //FARMACIAS SEGUNDA CIUDAD

    //Creacion Inventario farmacia Medallo
    medallo.push_back(add_inventory(1, "Acetaminofén 500 mg Frasco x 24 Tabletas", "Analgésico y antipirético", " TECNOQUÍMICAS S.A. " , 19.95, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(2, "Alcohol Mk Antiséptico Uso Externo x 700 ml", "Antiséptico ","TECNOQUIMICAS S.A. " , 10.0, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(3, "Viagra Sildenafil 50 mg Caja x 4 Tabletas", "Viagra ","Pfizer s.a. " , 49.9, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(4, "Shampoo Tío Nacho x 1 lt", "Antiséptico, Antiseborreico ","Tío Nacho " , 43.7, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(5, "Leche Magnesia MK Frasco x 120ml", "Antiácidos / Laxantes", " ASPEN COLOMBIANA SAS " , 8.35, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(6, "Birm Inmunomodulador Frasco x 120 ml", "Fitoterapéutico" ," Green Terra Life " , 100.0, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(7, "Noxpirin Plus x 12 Cápsulas", "Antigripal","LABORATORIOS PISA S.A. DE C.V. BAYER S.A. " , 16.2, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(8, "Noraver Garganta Menta Caja x 12 Tabletas", "Antiséptico y anestésico","TECNOQUIMICAS S.A. " , 20.85, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(9, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 9.95, "10%" ,0.90, 20));
    medallo.push_back(add_inventory(10, "Panotil B Frasco x 8 ml", "Antiinflamatorio" ," Zambon colombia " , 20.55, "10%" ,0.90, 20));

    //Creacion Inventario farmacia la nea
    la_nea.push_back(add_inventory(1, "Leche Magnesia MK Frasco x 120ml", "Antiácidos / Laxantes", " ASPEN COLOMBIANA SAS " , 8.4, "10%" ,0.90, 6));
    la_nea.push_back(add_inventory(2, "Advil Gripa x 10 capsulas", "Analgésico", " Pfizer S.A.S. " , 16.95, "10%" ,0.90, 8));
    la_nea.push_back(add_inventory(3, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 8.15, "10%" ,0.90, 3));
    la_nea.push_back(add_inventory(4, "SAL DE FRUTAS LUA PLUS CAJA X 20 SOB", "Antiflatulento", " TECNOQUÍMICAS S.A. " , 55.0, "10%" ,0.90, 4));
    la_nea.push_back(add_inventory(5, "Noraver Garganta Menta Caja x 12 Tabletas", "Antiséptico y anestésico","TECNOQUIMICAS S.A. " , 21.45, "10%" ,0.90, 12));
    la_nea.push_back(add_inventory(6, "Pedialyte Max Zinc Uva Frasco x 500 ml", "rehidratación ", " Abbott " , 8.5, "10%" ,0.90, 2));
    la_nea.push_back(add_inventory(7, "Alcohol Mk Antiséptico Uso Externo x 700 ml", "Antiséptico ","TECNOQUIMICAS S.A. " , 8.15, "10%" ,0.90, 13));
    la_nea.push_back(add_inventory(8, "Cura Cure Band Standard Translúcidas x 30 und", "Adhesivos y botiquín ","Cure band " , 3.7, "10%" ,0.90, 8));
    la_nea.push_back(add_inventory(9, "Birm Inmunomodulador Frasco x 120 ml", "Fitoterapéutico" ," Green Terra Life " , 120.0, "10%" ,0.90, 20));
    la_nea.push_back(add_inventory(10, "Digestar Fibra Natural Polvo Tarro X 300Gr", "Laxante" ," NATURAL FRESHLY " , 63.8, "20%" ,0.80, 8));

//FARMACIAS TERCER CIUDAD

  //Creacion inventario farmacia la costa
    la_costa.push_back(add_inventory(1, "SAL DE FRUTAS LUA PLUS CAJA X 20 SOB", "Antiflatulento", " TECNOQUÍMICAS S.A. " , 55.2, "10%" ,0.90, 3));
    la_costa.push_back(add_inventory(2, "Pedialyte Max Zinc Uva Frasco x 500 ml", "rehidratación ", " Abbott " , 8.95, "10%" ,0.90, 5));
    la_costa.push_back(add_inventory(3, "Advil Gripa x 10 capsulas", "Analgésico", " Pfizer S.A.S. " , 16.95, "20%" ,0.80, 7));
    la_costa.push_back(add_inventory(4, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 7.95, "10%" ,0.90, 3));
    la_costa.push_back(add_inventory(5, "Acetaminofén 500 mg Frasco x 24 Tabletas", "Analgésico y antipirético", " TECNOQUÍMICAS S.A. " , 20.35, "10%" ,0.90, 6));
    la_costa.push_back(add_inventory(6, "Digestar Fibra Natural Polvo Tarro X 300Gr", "Laxante" ," NATURAL FRESHLY " , 67.25, "20%", 0.80, 1));
    la_costa.push_back(add_inventory(7, "Leche Magnesia MK Frasco x 120ml", "Antiácidos / Laxantes", " ASPEN COLOMBIANA SAS " , 6.35, "10%" ,0.90, 14));
    la_costa.push_back(add_inventory(8, "Shampoo Tío Nacho Anticaída Aclarante x 1 lt", "Antiséptico, Antiseborreico ","Tío Nacho " , 40.0, "10%" ,0.90, 10));
    la_costa.push_back(add_inventory(9, "Panotil B Frasco x 8 ml", "Antiinflamatorio" ," Zambon colombia " , 18.95, "10%" ,0.90, 16));
    la_costa.push_back(add_inventory(10, "Noraver Garganta Menta Caja x 12 Tabletas", "Antiséptico y anestésico","TECNOQUIMICAS S.A. " , 27.8, "10%" ,0.90, 18));

  //Creacion inventario farmacia la rebaja
    la_rebaja.push_back(add_inventory(1, "Cura Cure Band Standard Translúcidas x 30 und", "Adhesivos y botiquín ","Cure band " , 5.5, "10%" ,0.90, 5));
    la_rebaja.push_back(add_inventory(2, "Shampoo Tío Nacho x 1 lt", "Antiséptico, Antiseborreico ","Tío Nacho " , 42.0, "30%" ,0.70, 8));
    la_rebaja.push_back(add_inventory(3, "Panotil B Frasco x 8 ml", "Antiinflamatorio" ," Zambon colombia " , 20.15, "10%" ,0.90, 13));
    la_rebaja.push_back(add_inventory(4, "Digestar Fibra Natural Polvo Tarro X 300Gr", "Laxante" ," NATURAL FRESHLY " , 63.8, "10%" ,0.90, 8));
    la_rebaja.push_back(add_inventory(5, "Alcohol Mk Antiséptico Uso Externo x 700 ml", "Antiséptico ","TECNOQUIMICAS S.A. " , 9.0, "10%" ,0.90, 16));
    la_rebaja.push_back(add_inventory(6, "Pedialyte Max Zinc Uva Frasco x 500 ml", "rehidratación ", " Abbott " , 9.0, "10%" ,0.90, 20));
    la_rebaja.push_back(add_inventory(7, "Viagra Sildenafil 50 mg Caja x 4 Tabletas", "Viagra ","Pfizer s.a. " , 43.75, "10%" ,0.90, 8));
    la_rebaja.push_back(add_inventory(8, "Mareol Caja x 12 Tabletas", "Antitusivo", " Pfizer S.A.S. " , 7.2, "10%" ,0.90, 3));
    la_rebaja.push_back(add_inventory(9, "Noxpirin Plus x 12 Cápsulas", "Antigripal","BAYER S.A. " , 15.3, "10%" ,0.90, 16));
    la_rebaja.push_back(add_inventory(10, "Advil Gripa x 10 capsulas", "Analgésico", " Pfizer S.A.S. " , 17.0, "10%" ,0.90, 10));
    

  bool flag = true;
  int option;
  string nombre;
  int cedula;

  while(flag == true){

    system("clear");
    
    // OPCIONES
    cout << "\n ------------------------------ \n";
    cout << "\n ---- FARMACIAS NACIONALES ---- \n";
    cout << "\n ------------------------------ \n";
    cout << "\n --------- BIENVENIDO --------- \n";
    cout << "\n ------------------------------ \n";
    cout << "\n Ingrese su nombre: ";
    cin.ignore();
    getline(cin,nombre);
    cout << "\n Ingrese su cedula: ";
    cin >> cedula;
    system("clear");
    cout << "\n ------------------------------ \n";
    cout << "\n ¿ EN QUE CIUDAD SE UBICA ? \n";
    cout << "\n ------------------------------ \n";
    cout << "[1] BOGOTA \n";
    cout << "[2] MEDELLIN \n";
    cout << "[3] BARRANQUILLA \n";
    cout << "\n --------------------- \n";
    cout << "[4] SALIR";
    cout << "\n --------------------- \n";
    
    //OPCIONES
    cout << "Ingrese la ciudad : ";
    cin >> option;
    
    switch(option){ /* SWITCH menú de ciudades */
      case 1:{
        
        vector<Productos> carrito;
        Productos product_selected;
        bool flag_2 = true;
        int farmacia;

        while(flag_2 == true){
          
          system("clear");

          cout<< "*********************** BOGOTÁ ***************************" <<endl;
          
          cout <<"\n --------------------- \n";
          cout <<"FARMACIAS DISPONIBLES";
          cout <<"\n --------------------- \n";
          cout <<"\n[1] FARMACIA SAN VICENTE\n";
          cout <<"\n[2] FARMACIA LA Y\n";
          cout <<"\n[3] VOLVER.. \n";
          cout <<"\n --------------------- \n";
          
          cout << "Que farmacia desea visitar: ";
          cin >> farmacia;
          string _farmacia;
          vector<Productos> sucursal;
          
            switch (farmacia){
              case 1:{ /* Primera Ciudad */
                sucursal = san_vicente;
                _farmacia = "san vicente";
              }break;
              case 2:{
                _farmacia = "la y";
                sucursal = la_y;
              }break;
              case 3:{
                flag_2 = false;
              }break;
              default:{
                cout << "[*] ERROR: OPCION NO VALIDA... \n";
                system("sleep 3s");
                flag_2 = false;
                }break;
              
            }

            bool keep_buying = true;
            
            while(keep_buying == true){
              
              system("clear");
              cout << "\n--------------------------------------------------\n";
              cout << "Productos disponibles en "<< _farmacia << ": \n";
              cout << "\n--------------------------------------------------\n";
              show_products(sucursal);
    
              int _option;
              cout << "\n-----------------------------------------\n";
              cout << "Ingrese el ID del producto a comprar: ";
              cin >> _option;
    
              if(search_product(sucursal, _option) == true){
                
                int cantidad;
                cout << "-----------------------------------------\n";
                cout << "Cuantos necesita ? : ";
                cin >> cantidad;
    
                for(int i = 0; i < sucursal.size(); i++){
                  if(sucursal[i].id == _option){
                    product_selected = sucursal[i];
                    break;
                  }
                }
                // VALIDAR CANTIDAD
                if(cantidad > 0 && cantidad <= product_selected.stock){

                  update_stock(sucursal, _option, cantidad);
                  carrito.push_back(add_inventory(product_selected.id, 
                                                  product_selected.nombre, 
                                                  product_selected.tipo, 
                                                  product_selected.laboratorio, 
                                                  (product_selected.precio * product_selected.descuento_num) * cantidad,//Descuento aplicado
                                                  product_selected.descuento,
                                                  product_selected.descuento_num, 
                                                  cantidad));
                  
                  cout << "[*] AGREGADO CON EXITO...\n";
                  system("sleep 3s");
      
                  cout << "\nDesea seguir comprando ? [s] SI / [n] NO ==>  ";
                  char _continue;
                  cin >> _continue;
      
                  if(_continue != 's' && _continue != 'S'){
                    // carrito.clear();
                    keep_buying = false;
                  }
                  
                }else{
                  cout << "[*] ERROR: LA CANTIDAD SOLICITADA NO ES VALIDA...\n";
                  system("sleep 3s");
                }
                
              }else{
                cout << "[*] ERROR: PRODUCTO NO ENCONTRADO.... \n";
                cout << "[*] VUELVA A INGRESAR... \n";
                system("sleep 3s");
              }
            }

            generate_recipe(carrito, nombre, cedula);

            char other;
            cout << "Desea visitar la otra sucursal ? : [s] SI / [n] NO  ===> ";
            cin >> other;

            if(other != 's' && other != 'S'){
              carrito.clear();
              flag_2 = false;
            }else{
              carrito.clear();
            }
          
        }
        
      }break;
      case 2:{/*Segunda ciudad */

        vector<Productos> carrito;
        Productos product_selected;
        bool flag_3 = true;
        int farmacia;

        while(flag_3 == true){
          
          system("clear");
          cout<< "*********************** MEDELLÍN ***************************" <<endl;
          
          cout <<"\n --------------------- \n";
          cout <<"FARMACIAS DISPONIBLES";
          cout <<"\n --------------------- \n";
          cout <<"\n[1] FARMACIA MEDALLO\n";
          cout <<"\n[2] FARMACIA LA NEA\n";
          cout <<"\n[3] VOLVER.. \n";
          cout <<"\n --------------------- \n";
          
          cout << "Que farmacia desea visitar: ";
          cin >> farmacia;
          string _farmacia;
          vector<Productos> sucursal;
          
            switch (farmacia){
              case 1:{ /* Primera Ciudad */
                sucursal = medallo;
                _farmacia = "medallo";
              }break;
              case 2:{
                _farmacia = "la nea";
                sucursal = la_nea;
              }break;
              case 3:{
                flag_3 = false;
              }break;
              default:{
                cout << "[*] ERROR: OPCION NO VALIDA...";
                flag_3 = false;
                }break;
              
            }

            bool keep_buying = true;
            
            while(keep_buying == true){
              
              system("clear");
              cout << "\n--------------------------------------------------\n";
              cout << "Productos disponibles en "<< _farmacia << ": \n";
              cout << "\n--------------------------------------------------\n";
              show_products(sucursal);
    
              int _option;
              cout << "\n-----------------------------------------\n";
              cout << "Ingrese el ID del producto a comprar: ";
              cin >> _option;
    
              if(search_product(sucursal, _option) == true){
                
                int cantidad;
                cout << "\n-----------------------------------------\n";
                cout << "Cuantos necesita ? : ";
                cin >> cantidad;
    
                for(int i = 0; i < sucursal.size(); i++){
                  if(sucursal[i].id == _option){
                    product_selected = sucursal[i];
                    break;
                  }
                }
                
                // VALIDAR CANTIDAD
                if(cantidad > 0 && cantidad <= product_selected.stock){

                  update_stock(sucursal, _option, cantidad);
                  carrito.push_back(add_inventory(product_selected.id, 
                                                  product_selected.nombre, 
                                                  product_selected.tipo, 
                                                  product_selected.laboratorio, 
                                                  (product_selected.precio * product_selected.descuento_num) * cantidad,
                                                  product_selected.descuento,
                                                  product_selected.descuento_num, 
                                                  cantidad));
                  
                  cout << "[*] AGREGADO CON EXITO...\n";
                  system("sleep 3s");
      
                  cout << "\nDesea seguir comprando ? [s] SI / [n] NO ==>  ";
                  char _continue;
                  cin >> _continue;
      
                  if(_continue != 's' && _continue != 'S'){
                    keep_buying = false;
                  }
                  
                }else{
                  cout << "[*] ERROR: LA CANTIDAD SOLICITADA NO ES VALIDA... \n";
                  system("sleep 3s");
                }
                
              }else{
                cout << "[*] ERROR: PRODUCTO NO ENCONTRADO.... \n";
                cout << "[*] VUELVA A INGRESAR... \n";
                system("sleep 3s");
              }
            }

            generate_recipe(carrito, nombre, cedula);
          
            char other;
            cout << "Desea visitar la otra sucursal ? : [s] SI / [n] NO  ===> ";
            cin >> other;

            if(other != 's' && other != 'S'){
              carrito.clear();
              flag_3 = false;
            }else{
              carrito.clear();
            }
        }      
        
      }break;
      case 3:{/*Tercera ciudad */
        
        vector<Productos> carrito;
        Productos product_selected;
        bool flag_4 = true;
        int farmacia;

        while(flag_4 == true){
          
          system("clear");
          cout<< "*********************** BARRANQUILLA ***************************" <<endl;
          cout <<"\n --------------------- \n";
          cout <<"FARMACIAS DISPONIBLES";
          cout <<"\n --------------------- \n";
          cout <<"\n[1] FARMACIA LA COSTA\n";
          cout <<"\n[2] FARMACIA LA REBAJA\n";
          cout <<"\n[3] VOLVER... \n";
          cout <<"\n --------------------- \n";
          
          cout << "Que farmacia desea visitar: ";
          cin >> farmacia;
          string _farmacia;
          vector<Productos> sucursal;
          
            switch (farmacia){
              case 1:{ /* Primera Ciudad */
                sucursal = la_costa;
                _farmacia = "la costa";
              }break;
              case 2:{
                _farmacia = "la rebaja";
                sucursal = la_rebaja;
              }break;
              case 3:{
                flag_4 = false;
              }break;
              default:{
                cout << "[*] ERROR: OPCION NO VALIDA...";
                flag_4 = false;
                }break;
              
            }

            bool keep_buying = true;
            
            while(keep_buying == true){
              
              system("clear");
              cout << "\n--------------------------------------------------\n";
              cout << "Productos disponibles en "<< _farmacia << ": \n";
              cout << "\n--------------------------------------------------\n";
              show_products(sucursal);
    
              int _option;
              cout << "\n-----------------------------------------\n";
              cout << "Ingrese el ID del producto a comprar: ";
              cin >> _option;
    
              if(search_product(sucursal, _option) == true){
                
                int cantidad;
                cout << "\n-----------------------------------------\n";
                cout << "Cuantos necesita ? : ";
                cin >> cantidad;
    
                for(int i = 0; i < sucursal.size(); i++){
                  if(sucursal[i].id == _option){
                    product_selected = sucursal[i];
                    break;
                  }
                }
                // VALIDAR CANTIDAD
                if(cantidad > 0 && cantidad <= product_selected.stock){

                  update_stock(sucursal, _option, cantidad);
                  carrito.push_back(add_inventory(product_selected.id, 
                                                  product_selected.nombre, 
                                                  product_selected.tipo, 
                                                  product_selected.laboratorio, 
                                                  (product_selected.precio * product_selected.descuento_num) * cantidad,
                                                  product_selected.descuento,
                                                  product_selected.descuento_num, 
                                                  cantidad));
                  
                  cout << "[*] AGREGADO CON EXITO... \n";
                  system("sleep 3s");
      
                  cout << "\nDesea seguir comprando ? [s] SI / [n] NO ==>  ";
                  char _continue;
                  cin >> _continue;
      
                  if(_continue != 's' && _continue != 'S'){
                    keep_buying = false;
                  }
                  
                }else{
                  cout << "[*] ERROR: LA CANTIDAD SOLICITADA NO ES VALIDA... \n";
                  system("sleep 3s");
                }
                
              }else{
                cout << "[*] ERROR: PRODUCTO NO ENCONTRADO.... \n";
                cout << "[*] VUELVA A INGRESAR... \n";
                system("sleep 3s");
              }
            }

            generate_recipe(carrito, nombre, cedula);

            char other;
            cout << "Desea visitar la otra sucursal ? : [s] SI ---- [n] NO  ===> ";
            cin >> other;

            if(other != 's' && other != 'S'){
              carrito.clear();
              flag_4 = false;
            }else{
              carrito.clear();
            }
          
        }
        
      }break;
      case 4:{
        cout << "[*] PROGRAMA TERMINADO... \n";
        flag = false;
      }break;
      default:{
        cout << "[*] ERROR: VALOR NO VALIDO... \n";
      }break;
    }
    
  }
  
}



/*mission complete!*/