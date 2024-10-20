#include <iostream>
#include <cstring> 
using namespace std;

class Computer {
    char* model;
    char* vendor;
    char* videocard;
    bool isSSD;
    float cpu_hz;
    int id;
    int ram;
    int disk_size;
    static int static_id;

public:
    Computer() {
        model = new char[20] {};
        vendor = new char[20] {};
        videocard = new char[20] {};
        isSSD = false;
        cpu_hz = 0.0;
        id = 0;
        ram = 0;
        disk_size = 0;
    }

    Computer(const char* model, const char* vendor, const char* videocard, bool isSSD, float cpu_hz, int ram, int disk_size) {
        SetModel(model);
        SetVendor(vendor);
        SetVideoCard(videocard);
        this->isSSD = isSSD;
        this->cpu_hz = cpu_hz;
        static_id++;
        this->id = static_id;
        this->ram = ram;
        this->disk_size = disk_size;
    }

    Computer(const Computer& object) {
        SetModel(object.model);
        SetVendor(object.vendor);
        SetVideoCard(object.videocard);
        isSSD = object.isSSD;
        cpu_hz = object.cpu_hz;
        id = object.id;
        ram = object.ram;
        disk_size = object.disk_size;
    }

    Computer& operator=(const Computer& object) {
        SetModel(object.model);
        SetVendor(object.vendor);
        SetVideoCard(object.videocard);
        isSSD = object.isSSD;
        cpu_hz = object.cpu_hz;
        id = object.id;
        ram = object.ram;
        disk_size = object.disk_size;
        return *this;
    }

    const char* GetModel() const {
        return this->model;
    }

    void SetModel(const char* model) {
        delete[] this->model;
        int len = 0;
        while (model[len] != '\0') {
            len++;
        }
        this->model = new char[len + 1] {};
        for (size_t i = 0; i< len; i++)
        {
            this->model[i] = model[i];
        }
        this->model[len] = '\0';
    }
 
    const char* GetVendor() const {
        return this->vendor;
    }

    void SetVendor(const char* vendor) {
        delete[] this->vendor;
        int len = 0;
        while (vendor[len] != '\0') {
            len++;
        }
        this->vendor = new char[len + 1] {};
        for (size_t i = 0; i < len; i++)
        {
            this->vendor[i] = vendor[i];
        }
        this->vendor[len] = '\0';
    }

    const char* GetVideoCard() const {
        return this->videocard;
    }

    void SetVideoCard(const char* videocard) {
        delete[] this->videocard;
        int len = 0;
        while (videocard[len] != '\0') {
            len++;
        }
        this->videocard = new char[len + 1] {};
        for (size_t i = 0; i < len; i++)
        {
            this->videocard[i] = videocard[i];
        }
        this->videocard[len] = '\0';
    }

    bool GetIsSSD() const {
        return this->isSSD;
    }

    void SetIsSSS(bool isSSD) {
        this->isSSD = isSSD;
    }

    float GetCpuHz() const {
        return this->cpu_hz;
    }

    void SetCpuHz(float cpu_hz) {
        if (cpu_hz < 1.8) {
            cout << "Wrong cpu hz";
        }
        else {
            this->cpu_hz = cpu_hz;
        }
    }
    
    int GetID() const {
        return this->id;
    }

    void SetID(int id){
        this->id = id;
    }

    int GetRam() const {
        return this->ram;
    }

    void SetRam(int ram) {
        if (ram < 1) {
            cout << "Wrong ram";
        }
        else {
            this->ram = ram;
        }
    }

    int GetDiskSize() const {
        return this->disk_size;
    }

    void SetDiskSize(int disk_size) {
        if (disk_size < 64) {
            cout << "Wrong disk size";
        }
        else {
            this->disk_size = disk_size;
        }
    }

    friend ostream& operator<<(ostream& out, const Computer& object) {
        out << "ID: " << object.id << endl;
        out << "Model: " << object.model << endl;
        out << "Vendor: " << object.vendor << endl;
        out << "VideoCard: " << object.videocard << endl;
        out << "IsSSD: " << (object.isSSD) << endl;
        out << "Cpu Hz: " << object.cpu_hz << endl;
        out << "Ram: " << object.ram << endl;
        out << "Disk size: " << object.disk_size << endl;
        out << "-------------------------------";
        return out;
    }

    friend istream& operator>>(istream& in, Computer& object) {
        cout << "Enter new model: ";
        in.ignore();
        in.getline(object.model, 20);

        cout << "Enter new vendor: ";
        in.getline(object.vendor, 20);

        cout << "Enter new videocard: ";
        in.getline(object.videocard, 20);

        cout << "Enter new isSSD: ";
        in >> object.isSSD;

        cout << "Enter new cpu hz: ";
        in >> object.cpu_hz;

        cout << "Enter new ram: ";
        in >> object.ram;

        cout << "Enter new disk size: ";
        in >> object.disk_size;

        return in;
    }

    ~Computer() {
        delete[] model;
        delete[] vendor;
        delete[] videocard;
    }
};


int Computer::static_id = 0;


class ComputerStore{
    char* store_name;
    char* store_address;
    Computer** computers;
    int computer_count;

public:
    ComputerStore() {
        store_name = new char[20] {};
        store_address = new char[20] {};
        computers = nullptr;
        computer_count = 0;
    }

    ComputerStore(const char* store_name, const char* store_address, Computer** computers, int computer_count) :ComputerStore() {
        SetStoreName(store_name);
        SetStoreAddress(store_address);
        SetComputers(computers,computer_count);
        this->computer_count = computer_count;
    }

    ComputerStore(const ComputerStore& computer) {
        this->store_name = new char[20] {*computer.store_name};
        this->store_address = new char[20] {*computer.store_address};
        this->computers = new Computer * [computer_count] {};
        for (size_t i = 0; i < computer_count; i++)
        {
            this->computers[i] = computer.computers[i];
        }
    }

    ComputerStore& operator=(const ComputerStore& computer) {
        this->store_name = new char[20] {*computer.store_name};
        this->store_address = new char[20] {*computer.store_address};
        this->computers = new Computer * [computer_count] {};
        for (size_t i = 0; i < computer_count; i++)
        {
            this->computers[i] = computer.computers[i];
        }
        return *this;
    }

    
    char* GetStoreName() const {
        return store_name;
    }

    void SetStoreName(const char* store_name) {
        delete[] this->store_name;
        int len = 0;
        while (store_name[len] != '\0') {
            len++;
        }
        this->store_name = new char[len + 1]; 
        for (size_t i = 0; i < len; i++) 
        {
            this->store_name[i] = store_name[i];
        }
        this->store_name[len] = '\0'; 
    }

    char* GetStoreAddress() const {
        return store_address;
    }

    void SetStoreAddress(const char* store_address) {
        delete[] this->store_address;
        int len = 0;
        while (store_address[len] != '\0') {
            len++;
        }
        this->store_address = new char[len + 1];
        for (size_t i = 0; i < len; i++) 
        {
            this->store_address[i] = store_address[i];
        }
        this->store_address[len] = '\0';
    }

    Computer** GetComputerss() const {
        return computers;
    }

    void SetComputers(Computer** computers, int computer_count) {
        for (int i = 0; i < this->computer_count; i++) {
            delete this->computers[i];
        }
        delete[] this->computers;

        this->computer_count = computer_count;
        this->computers = new Computer * [computer_count];
        for (int i = 0; i < computer_count; ++i) {
            this->computers[i] = new Computer(*computers[i]);
        }
    }
 
    void AddComputer() {
        char* new_model = new char[20] {};
        cout << "Enter new model: ";
        cin.ignore();
        cin.getline(new_model, 20);

        char* new_vendor = new char[20] {};
        cout << "Enter new vendor: ";
        cin.getline(new_vendor, 20);

        char* new_videocard = new char[20] {};
        cout << "Enter new videocard: ";
        cin.getline(new_videocard, 20);

        bool new_isSSD;
        cout << "Enter new isSSD: ";
        cin >> new_isSSD;

        float new_cpu_hz;
        cout << "Enter new cpu hz: ";
        cin >> new_cpu_hz;

        int new_ram;
        cout << "Enter new ram: ";
        cin >> new_ram;

        int new_disk_size;
        cout << "Enter new disk size: ";
        cin >> new_disk_size;

        Computer* new_computer = new Computer{ new_model,new_vendor,new_videocard,new_isSSD,new_cpu_hz,new_ram,new_disk_size };
        Computer** new_computers = new Computer * [computer_count + 1] {};
        for (size_t i = 0; i < computer_count; i++)
        {
            new_computers[i] = this->computers[i];
        }
        new_computers[computer_count] = new_computer;
        delete[]computers;
        computers = new_computers;
        computer_count++;
    }

    void DeleteProduct(int deleted_id) {
        bool result = false;
        int index = -1;
        for (size_t i = 0; i < computer_count; i++)
        {
            if (computers[i]->GetID() == deleted_id) {
                index = i;
                result = true;
                break;
            }
        }
        if (result) {
            delete computers[index];
            Computer** new_computers = new Computer * [computer_count - 1] {};
            int k = 0;
            for (int i = 0; i < computer_count; i++)
            {
                if (i != index) {
                    new_computers[k++] = computers[i];
                }
            }
            delete[] computers;
            computers = new_computers;
            computer_count--;

            for (int i = 0; i < computer_count; i++)
            {
                computers[i]->SetID(i + 1);
            }
        }
        else {
            cout << "Not Found" << endl;
        }

    }

    friend ostream& operator<<(ostream& out, const ComputerStore& store) {
        out << "Store name: " << store.store_name << endl;
        out << "Store address: " << store.store_address << endl;
        for (size_t i = 0; i < store.computer_count; i++)
        {
            out << *store.computers[i] << endl;
        }
        return out;
    }

    friend istream& operator>>(istream& in, ComputerStore& computer) {
        cout << "Enter story name:";
        in.getline(computer.store_name, 20);
        cout << endl;
        cout << "Enter story address:";
        in.getline(computer.store_address, 20);
        return in;
    }

    ~ComputerStore() {
        delete[] store_name;
        delete[] store_address;
        for (size_t i = 0; i < computer_count; i++)
        {
            delete computers[i];
        }
        delete[] computers;
    }
};


                                                                  
void main() {
    Computer* comp1 = new Computer{ "Model1", "Vendor1", "VideoCard1", true, 2.3, 8, 256};
    Computer* comp2 = new Computer{ "Model2", "Vendor2", "VideoCard2", false, 2.5, 16, 512};

    //cout << *comp1 << endl;
    //cout << *comp2 << endl;

    int size = 2;
    Computer** computers = new Computer * [size] {comp1, comp2};

    ComputerStore computers_store("Store Name1", "Store Address1", computers, size);
    //cout << computers_store << endl;

    //ComputerStore* new_compstore= new ComputerStore("New Name1", "New Address1", computers, size);
    //cout << *new_compstore;
    //new_compstore->AddComputer();
    //cout << *new_compstore;

    int id;
    cout << "Enter id: ";
    cin >> id;
    computers_store.DeleteProduct(id);
    cout << computers_store << endl;


}

