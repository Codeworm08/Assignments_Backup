
import java.util.*;

class Person {
    String name;
    long phone_no;
    String email;
    String pno;// premises no
    String street;
    String city;
    long pin;
    String state;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Long getPhone() {
        return phone_no;
    }

    public void setPhone(Long phone_no) {
        this.phone_no = phone_no;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPno() {
        return pno;
    }

    public void setPno(String pno) {
        this.pno = pno;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public long getPin() {
        return pin;
    }

    public void setPin(long pin) {
        this.pin = pin;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    void getAddress(Scanner sc) {
        System.out.print("Enter the Premises number: ");
        pno = sc.nextLine();

        System.out.print("Enter the Street: ");
        street = sc.nextLine();

        System.out.print("Enter the City: ");
        city = sc.nextLine();

        System.out.print("Enter the Pin: ");
        pin = sc.nextLong();
        sc.nextLine();
        System.out.print("Enter the state: ");
        state = sc.nextLine();

    }

    void showAddress() {
        System.out.print("Address is:" + pno + " , " + street + ", " + city + ", " + state + ", " + pin + "\n");

    }

    void changeAddress(Scanner sc) {
        System.out.println("1- Premises no \n 2- Street \n 3- City \n 4- Pin \n 5- State");
        System.out.println("Specify what need to be changed");
        int c = sc.nextInt();
        switch (c) {
            case 1:
                sc.nextLine();
                System.out.print("Enter the new Premises number: ");
                pno = sc.nextLine();
                break;
            case 2:
                sc.nextLine();
                System.out.print("Enter the new Street:");
                street = sc.nextLine();
                break;
            case 3:
                System.out.print("Enter the  new City:");
                sc.nextLine();
                city = sc.nextLine();
                break;
            case 4:
                sc.nextLine();
                System.out.print("Enter the new Pin:");
                pin = sc.nextLong();
                break;
            case 5:
                sc.nextLine();
                System.out.print("Enter the new state:");
                state = sc.nextLine();
                break;
            default:
                System.out.print("wrong input");
                break;
        }
    
    }
}

class Student extends Person {
    int roll;
    String course;

    public void setRoll(int roll) {
        this.roll = roll;
    }

    public int getRoll() {
        return roll;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }
}

class Faculty extends Person {
    String empid;
    String department;
    String specialisation;

    public String getId() {
        return empid;
    }

    public void setId(String empid) {
        this.empid = empid;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getSpecialisation() {
        return specialisation;
    }

    public void setSpecialisation(String specialisation) {
        this.specialisation = specialisation;
    }
}

public class Q2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students:  ");
        int ns = sc.nextInt();
        System.out.print("\nEnter the number of faculty:  ");
        int nf = sc.nextInt();

        Student[] st = new Student[ns];

        Faculty[] fa = new Faculty[nf];
        for (int i = 0; i < ns; i++) {
            st[i] = new Student();
            System.out.println("Enter the record for student: " + (i + 1));
            System.out.println("Enter the Roll Number: ");
            int roll = sc.nextInt();
            sc.nextLine();
            st[i].setRoll(roll);

            System.out.print("Enter the Name: ");
            String n = sc.nextLine();
            st[i].setName(n);
            // sc.nextLine();
            System.out.print("Enter the Phone Number: ");
            long phno = sc.nextLong();
            st[i].setPhone(phno);
            sc.nextLine();
            System.out.print("Enter the Email Address: ");
            String eid = sc.nextLine();
            st[i].setEmail(eid);
            // sc.nextLine();
            System.out.print("Enter the Course of study: ");
            String study = sc.nextLine();
            st[i].setCourse(study);
            // sc.nextLine();
            System.out.println("Enter Address: ");
            st[i].getAddress(sc);

        }
        for (int i = 0; i < nf; i++) {
            fa[i] = new Faculty();
            System.out.println("Enter the record for Faculty: " + (i + 1));
            // sc.nextLine();
            System.out.print("Enter the Employee Id: ");
            String eid = sc.nextLine();
            fa[i].setId(eid);

            System.out.print("Enter the Name: ");
            String n = sc.nextLine();
            fa[i].setName(n);
            // sc.nextLine();

            System.out.print("Enter the Department: ");
            String dept = sc.nextLine();
            fa[i].setDepartment(dept);

            System.out.print("Enter the Specialisation: ");
            String s = sc.nextLine();
            fa[i].setSpecialisation(s);
            // sc.nextLine();

            System.out.print("Enter the Phone Number:");
            long phno = sc.nextLong();
            fa[i].setPhone(phno);
            sc.nextLine();

            System.out.print("Enter the Email Address: ");
            String email = sc.nextLine();
            fa[i].setEmail(email);

            System.out.println("Enter the Address: ");
            fa[i].getAddress(sc);
            sc.nextLine();
        }

        System.out.println("\n\nDetails of the Faculty:\n\n");
        for (int i = 0; i < nf; i++) {
            System.out.println("Emp_id : " + fa[i].getId());
            System.out.println("Name : " + fa[i].getName());
            System.out.println("Email-id : " + fa[i].getEmail());
            fa[i].showAddress();
            System.out.println("Phone Number : " + fa[i].getPhone());
            System.out.println("Department : " + fa[i].getDepartment());
            System.out.println("Specialisation : " + fa[i].getSpecialisation());
            System.out.println();
        }
        System.out.println("\n\nDetails of the Students:\n\n");
        for (int i = 0; i < nf; i++) {
            System.out.println("Roll No : " + st[i].getRoll());
            System.out.println("Name : " + st[i].getName());
            System.out.println("Email-id : " + st[i].getEmail());
            st[i].showAddress();
            System.out.println("Phone Number : " + st[i].getPhone());
            System.out.println("Department : " + st[i].getCourse());
            System.out.println();
        }
        System.out.println();
        do {
            System.out.print("Do you what to change the address details(0/1)");
            int chh = sc.nextInt();
            if (chh == 1) {
                System.out.print("1- change address details of the student\n");
                System.out.print("2- change address details of the faculty member");
                System.out.print("\nEnter Choice");
                sc.nextLine();
                int cho = sc.nextInt();
                switch (cho) {
                    case 1: {
                        int flag = 0;
                        System.out.print("Enter the roll no of the student");
                        int r = sc.nextInt();
                        for (int j = 0; j < ns; j++) {
                            if (st[j].getRoll() == r) {
                                st[j].changeAddress(sc);
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0)
                            System.out.println("Not Found");
                    }
                        break;
                    case 2: {
                        int flag1 = 0;

                        System.out.print("Enter the emp id of the Employee:");
                        sc.nextLine();
                        String e = sc.nextLine();
                        for (int j = 0; j < nf; j++) {
                            if (fa[j].getId().equals(e)) {
                                {
                                    fa[j].changeAddress(sc);
                                    flag1 = 1;
                                    break;
                                }
                            }
                        }
                        if (flag1 == 0)
                            System.out.println("Not Found!");
                    }
                        break;
                    default:
                        System.out.println("Wrong Choice!");
                }
            } else
                break;
        } while (true);

        System.out.println("\n\nDetails of the Faculty:\n\n");
        for (int i = 0; i < nf; i++) {
            System.out.println("Emp_id : " + fa[i].getId());
            System.out.println("Name : " + fa[i].getName());
            System.out.println("Email-id : " + fa[i].getEmail());
            fa[i].showAddress();
            System.out.println("Phone Number : " + fa[i].getPhone());
            System.out.println("Department : " + fa[i].getDepartment());
            System.out.println("Specialisation : " + fa[i].getSpecialisation());

        }
        System.out.println("\n\nDetails of the Students:\n\n");
        for (int i = 0; i < nf; i++) {
            System.out.println("Roll No : " + st[i].getRoll());
            System.out.println("Name : " + st[i].getName());
            System.out.println("Email-id : " + st[i].getEmail());
            st[i].showAddress();
            System.out.println("Phone Number : " + st[i].getPhone());
            System.out.println("Department : " + st[i].getCourse());
        }
        sc.close();
    }
}
