#include <iostream>
#include <limits> 

using namespace std;


void processNumber(int current_number, int& min_val, int& count_val) {
    
    count_val++;
    if (current_number < min_val) {
        min_val = current_number;
    }
}

int main() {
    int input_number;
    int total_count = 0;
    int minimum_value = numeric_limits<int>::max();

    cout << "===================================================" << endl;
    cout << " " << endl;
    cout << "===================================================" << endl;

    // 6. ใช้คำสั่งวนซ้ำ while loop
    while (true) {
        // 1. รับค่าตัวเลขจากผู้ใช้ทีละค่า
        cout << "ป้อนตัวเลข (หรือ 0 เพื่อออกจากโปรแกรม): ";
        cin >> input_number;

        // 4. หากผู้ใช้ป้อนค่า 0 ให้หยุดการทำงานทันที
        if (input_number == 0) {
            break; // ออกจาก while loop
        }

        // 2. ส่งค่าไปประมวลผลในฟังก์ชันแบบ Reference
        processNumber(input_number, minimum_value, total_count);

        // แสดงสถานะปัจจุบัน (ไม่จำเป็นต้องทำ แต่ช่วยในการตรวจสอบ)
        cout << "    [สถานะ] นับ: " << total_count << ", ค่าต่ำสุดปัจจุบัน: " << minimum_value << endl;
    }

    // 5. แสดงผลลัพธ์สุดท้าย
    cout << "\n===================================" << endl;
    cout << "          สรุปผลลัพธ์" << endl;
    cout << "===================================" << endl;

    // ตรวจสอบว่ามีการป้อนค่าตัวเลขอย่างน้อยหนึ่งค่าหรือไม่
    if (total_count > 0) {
        // แสดงจำนวนตัวเลขที่รับเข้ามาทั้งหมด
        cout << "จำนวนตัวเลขที่รับเข้ามาทั้งหมด: " << total_count << " ค่า" << endl;
        // แสดงค่าตัวเลขที่น้อยที่สุด
        cout << "ค่าตัวเลขที่น้อยที่สุด (Minimum): " << minimum_value << endl;
    }
    else {
        cout << "ไม่มีการป้อนตัวเลขใดๆ (ยกเว้น 0) เข้ามาในระบบ" << endl;
    }

    return 0;
}