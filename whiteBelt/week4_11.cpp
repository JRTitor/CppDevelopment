#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* �仍�� �亠��亳�仂于舒仆亳�� 仗仂于��舒于仍�磺�亠 ��ﾐ莞� 从仂亟, �亠舒仍亳亰��ﾑ�亳亶 �舒亰仍亳�仆仂亠 仗仂于亠亟亠仆亳亠 ��仂亶 ��仆从亳亳:
       * 仆仂�仄舒仍�仆�亶 于仂亰于�舒� ���仂从仂于仂亞仂 亰仆舒�亠仆亳��
       * 于�弍�仂� 亳�从仍�ﾑ�亠仆亳�� system_error
       * 于�弍�仂� 亟��亞仂亞仂 亳�从仍�ﾑ�亠仆亳�� � �仂仂弍�亠仆亳亠仄.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
      try{
        last_fetched_time = AskTimeServer();
        return last_fetched_time;
      } catch (system_error& se) {
        return last_fetched_time;
      }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
