#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector> //
#include <QString> //

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// โครงสร้างข้อมูล (Struct)
struct Task {
    QString name;
    int remainingMinutes;
    int deadlineDay;
    int deadlineHour;
    int deadlineMinute;
    double stressIndex;
};

//
struct Day {
    QString timeSlots[1440]; // 1440 นาทีต่อวัน
    Day() {
        for(int i=0; i<1440; i++) timeSlots[i] = "Free";
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//
private slots:
    void on_btnUpdateTime_clicked();   // อัปเดตเวลาปัจจุบัน
    void on_btnAddRoutine_clicked();   // เพิ่มกิจกรรมประจำ (Routine)
    void on_btnAddTask_clicked();      // เพิ่มงาน (To-Do)
    void on_btnCompleteTask_clicked(); // ลบงานที่เสร็จ

private:
    Ui::MainWindow *ui;

    // ตัวแปรเก็บข้อมูลหลัก
    std::vector<Day> week;
    std::vector<Task> taskList;

    // ตัวแปรเวลาปัจจุบัน (ค่าเริ่มต้น: วันที่ 1 เวลา 08:00)
    int curDay = 1;
    int curHour = 8;
    int curMin = 0;

    // ฟังก์ชันช่วยคำนวณและแสดงผล
    int toMinutes(int h, int m);
    int getNetFreeMinutes(int dDay, int dHour, int dMinute);
    void updateDashboard();       // คำนวณ Stress Index และเรียกฟังก์ชันวาดตาราง
    void refreshScheduleTable();  // วาดตารางตารางเรียน/กิจกรรม
    void refreshToDoTable();      // วาดตาราง To-Do List
};

#endif // MAINWINDOW_H
