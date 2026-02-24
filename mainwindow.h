#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector> // ส่วนที่2
#include <QString> //ส่วนที่2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//  ส่วนที่2
struct Task {
    QString name;
    int remainingMinutes;
    int deadlineDay;
    int deadlineHour;
    int deadlineMinute;
    double stressIndex;
};

//  ส่วนที่2
struct Day {
    QString timeSlots[1440];
    Day() {
        for(int i=0; i<1440; i++) timeSlots[i] = "Free";
    }
};

// ตรงนี้ไม่ต้อง
class MainWindow : public QMainWindow
{
    Q_OBJECT

// นี้ก็ไม่ต้อง
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


// ส่วนที่1
private slots:
    void on_btnUpdateTime_clicked();
    void on_btnAddRoutine_clicked();
    void on_btnAddTask_clicked();
    void on_btnCompleteTask_clicked();

private:
    Ui::MainWindow *ui;

    // ส่วนที่3
    std::vector<Day> week;
    std::vector<Task> taskList;

    // ส่วนที่2
    int curDay = 1;
    int curHour = 0;
    int curMin = 0;

    int toMinutes(int h, int m);  //ส่วนที่2
    int getNetFreeMinutes(int dDay, int dHour, int dMinute); //ส่วนที่2
    void updateDashboard(); //ส่วนที่1 ของเต้
    void refreshScheduleTable(); //ส่วนที่3 ของเต้
    void refreshToDoTable(); //ส่วนที่3 ของเต้
};

#endif // MAINWINDOW_H
