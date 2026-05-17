
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Order {
    int timeStep;
    char O_Type;
    int processTime;
};

struct Truck {
    char O_Type;
    int id;
};

int main() {

    srand(time(0));
    int time_steps = 30;
    int truck_capacity = 5;
    char order_types[3] = {'S', 'M', 'B'};

    queue<Order> Queue_S, Queue_M, Queue_B;
    stack<Truck> TruckStack;

    vector<Order> OrderLog;
    vector<Order> newOrders;

    int doneS=0,doneM=0,doneB=0;//counter for how many x-type orders have been made so far
    int truckS=0,truckM=0,truckB=0;//counter for how many x-type trucks have been dispatched so far

    for(int t=1;t<=time_steps;t++){

        newOrders.clear();
        int num_new_orders=rand() % 4;

        for (int i=0;i<num_new_orders;i++) {
            char O_Type = order_types[rand() % 3];
            int processing_time = (rand() % 4) + 1;
            Order o = {t, O_Type, processing_time};

            if (O_Type == 'S') Queue_S.push(o);
            else if (O_Type == 'M') Queue_M.push(o);
            else Queue_B.push(o);

            OrderLog.push_back(o);
            newOrders.push_back(o);
        }

        // PROCESS S
        if (!Queue_S.empty()) {
            Order &f = Queue_S.front();
            f.processTime--;

            if (f.processTime <= 0) {
                Queue_S.pop();
                doneS++;

                if (doneS == truck_capacity) {
                    truckS++;
                    TruckStack.push({'S', truckS});
                    doneS = 0;
                }
            }
        }

        // PROCESS M
        if (!Queue_M.empty()) {
            Order &f = Queue_M.front();
            f.processTime--;

            if (f.processTime <= 0) {
                Queue_M.pop();
                doneM++;

                if (doneM == truck_capacity) {
                    truckM++;
                    TruckStack.push({'M', truckM});
                    doneM = 0;
                }
            }
        }

        // PROCESS B
        if (!Queue_B.empty()) {
            Order &f = Queue_B.front();
            f.processTime--;

            if (f.processTime <= 0) {
                Queue_B.pop();
                doneB++;

                if (doneB == truck_capacity) {
                    truckB++;
                    TruckStack.push({'B', truckB});
                    doneB = 0;
                }
            }
        }

        // OUTPUT
        cout << "Time Step " << t << "\n";

        cout << "New Orders: ";
        for (auto &o : newOrders)
            cout << o.O_Type << " ";
        cout << "\n";

        cout << "Queue S: " << Queue_S.size() << "\n";
        cout << "Queue M: " << Queue_M.size() << "\n";
        cout << "Queue B: " << Queue_B.size() << "\n";

        cout << "Stack: ";
        if (TruckStack.empty()) {
            cout << "empty";
        } else {
            stack<Truck> temp = TruckStack;
            while (!temp.empty()) {
                cout << "Truck" << temp.top().id << "[" << temp.top().O_Type << "] ";
                temp.pop();
            }
        }

        cout << "\n\n";
    }

    cout << "Generated Orders (time_step,O_Type,processing_time)\n";
    for (auto &o : OrderLog) {
        cout << o.timeStep << "," << o.O_Type << "," << o.processTime << "\n";
    }

    return 0;
}