#include <iostream>



class UART{
    private:
        UART(): data{0}{}

        int data;
    public:

    static UART& getInstance()
    {
        static UART Temp_Uart;
        return Temp_Uart;
    }

    void SendData(int Data)
    {
        this->data = Data;
    }

    int GetData()
    {
        return this->data;
    }
};

int main()
{
    UART &u1 =  UART::getInstance();
    u1.SendData(10);
    std::cout << u1.GetData() << std::endl;
}