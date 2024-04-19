#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
void TipoDeInstruccion(std::string linea);

class Vector {

    private:
        unsigned int capacity;
        unsigned int size;
        string* storage;
    public:
    // Constructor para inicializar los valores de size_, capacity_ y reservar memoria inicial.
        Vector() {
            capacity = 10; // Inicialmente, el vector tiene capacidad para 10 elementos.
            size = 0;      // Al comienzo, el vector está vacío.
            storage = new string[capacity]; // Reservar memoria para la capacidad inicial.
        }
        bool empty() {return size == 0;}
        unsigned int size_() {return size;} 
        unsigned int capacity_() {return capacity;}

        // Agrega un elemento al final del vector.
        void push_back(string elem) {
            if (size == capacity) { // Si el vector está lleno, aumentar su capacidad.
                std::cout << "Arreglo interno lleno, redimensionando..." << endl;
                resize_();
            }
        
            storage[size] = elem; // Agregar el nuevo elemento.
            size++; // Incrementar el tamaño actual del vector.
        }
        void resize_() {
            string* newStorage = new string[capacity * 2]; // Crear nuevo arreglo con el doble de capacidad.
            for (unsigned int i = 0; i < size; i++) {
                newStorage[i] = storage[i]; // Copiar elementos al nuevo arreglo.
            }
            delete[] storage; // Liberar la memoria del arreglo antiguo.
            storage = newStorage; // Actualizar el puntero para que apunte al nuevo arreglo.
            capacity *= 1.5; // Actualizar la capacidad.
        }
        std::string at(unsigned int p) {
            if (size >= p)
                return storage[p];
            else {
                cout << "Error: El vector está vacío." << endl;
                exit (1); // Finaliza el programa con un error.
            }
        }
        void mostrarVector(){
            for(unsigned int i=0; i<size; i++){
                std::cout<<storage[i]<<endl;
            }
        }
};


void clasificar(Vector& v){
    for(unsigned int i=0; i<v.size_(); i++){
        std::string linea = v.at(i);
        for(unsigned int j=0; j<linea.size(); j++){
            char caracter = linea[j];
            if(caracter != ':'){
                if(caracter!= '.'){
                    if(caracter!= '/'){
                        if(caracter!= ','){
                        }else{
                            std::cout<<linea<<" es una instruccion"<<endl;
                            TipoDeInstruccion(linea);
                            break;
                        }
                    }else{
                        std::cout<<linea<<" es un comentario"<<endl;                        
                        break;
                        }
                }else{
                    std::cout<<linea<<" es una directiva"<<endl;
                    break;
                }
            }else{
                std::cout<<linea<<" es una etiqueta"<<endl;
                break;
                }

        }

    }
}

void TipoDeInstruccion(Vector& t, std::string linea){
    std::string instruccion = linea; 
    //separar el string "instruccion" en sub-cadenas segun cada espacio en blanco
    std::stringstream ss(instruccion);
    std::string subcadena;
    while(getline(ss, subcadena, ' ')){
        if(!subcadena.empty()){
            t.push_back(subcadena);
            t.mostrarVector();  
        }
        std::cout<<subcadena<<endl;
    }

}

void LeerArchivo(Vector& v, const std::string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            if(!linea.empty()){
                v.push_back(linea);
            }
        }
        archivo.close();
    }
    else{
        std::cout<<"No se pudo abrir el archivo"<<endl;
    }

}

class Instrucciones{
    private:
        class Rtype
        {
            private:
                //string add, sub, sll, slt, sltu, xor_, srl, sra, or_, and_ = "0110011";
                string opcode = "0110011";
                string rd= ""; //5 bits    
                string funct3 = ""; //3 bits
                string rs1 = ""; //5 bits
                string rs2 = ""; //5 bits
                string funct7 = ""; //7 bits


            public:
                /*string add_(){return add;}
                string sub_(){return sub;}
                string sll_(){return sll;}
                string slt_(){return slt;}
                string sltu_(){return sltu;}
                string xor_(){return xor_;}
                string srl_(){return srl;}
                string sra_(){return sra;}
                string or_(){return or_;}
                string and_(){return and_;}*/
                std::string getOpcode(){return opcode;}
                void setRd(string rd_){rd = rd_;}
                void setFunct3(string funct3_){funct3 = funct3_;}
                void setRs1(string rs1_){rs1 = rs1_;}
                void setRs2(string rs2_){rs2 = rs2_;}


                


        };

        class Itype{
            private: 
                //string addi, slti, sltiu, xori, ori, andi, slli, srli, srai  = "0010011";
                //string lb, lh, lbu, lhu = "0000011";

                
                
            public:
                /*string addi_(){return addi;}
                string slti_(){return slti;}
                string sltiu_(){return sltiu;}
                string xori_(){return xori;}
                string ori_(){return ori;}
                string andi_(){return andi;}
                string slli_(){return slli;}
                string srli_(){return srli;}
                string srai_(){return srai;}
                string lb_(){return lb;}
                string lh_(){return lh;}
                string lw_(){return lw;}
                string lbu_(){return lbu;}
                string lhu_(){return lhu;}
                string jalr_(){return jalr;}*/

        };
        class Stype{
            private:
                string sb = "0100011";
                string sh = "0100011";
                string sw = "0100011";
            public:
                string sb_(){return sb;}
                string sh_(){return sh;}
                string sw_(){return sw;}
        };
        class Btype{
            private:
                //string beq, bne, blt, bge, bltu, bgeu = "1100011";
                string opcode = "1100011";
                string funct3 = "";
               // string imm[];
                string rs1 = "";
                string rs2 = "";
                string imm = "";

                
            public:
                /*string beq_(){return beq;}
                string bne_(){return bne;}
                string blt_(){return blt;}
                string bge_(){return bge;}
                string bltu_(){return bltu;}
                string bgeu_(){return bgeu;}*/
        };
        class Utype{
            private:
                string lui = "0110111";
                string auipc = "0010111";
            public:
                string lui_(){return lui;}
                string auipc_(){return auipc;}
        };
        class Jtype{
            private:
                string jal = "1101111";
            public:
                string jal_(){return jal;}
        };
    

    public:
        Rtype rtype;
        Itype itype;
        Stype stype;
        Btype btype;
        Utype utype;
        Jtype jtype;

        



};

void Codificar(Vector& v, Instrucciones& i){

}


int main()
{
    Vector v;
    Vector t;
    Vector f;

    Instrucciones i;
    LeerArchivo(v, "code.txt");
    std::cout<<v.size_()<<endl;
    std::cout<<v.capacity_()<<endl;
    clasificar(v);
    //v.mostrarVector();

    return 0;
}