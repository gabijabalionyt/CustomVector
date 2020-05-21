#include "biblioteka.h"

Person::Person() {}

Person::Person(string Name, string Surname)
{

    Name_ = Name;
    Surname_ = Surname;
}

Person::~Person() {}


Student::Student(const Student& OldClass)  {
       Name_ = OldClass.Name_;
    Surname_ = OldClass.Surname_;
    Homework = OldClass.Homework;
    Exam = OldClass.Exam;
    Averange = OldClass.Averange;
    Median = OldClass.Median;
    FMedian = OldClass.FMedian;
    FAverange = OldClass.FAverange;

}


Student::Student()
{
    int Exam = 0;
    double Averange = 0.0;
    double Median = 0.0;
    double FMedian = 0.0;
    double FAverange = 0.0;
}

Student::~Student() {}

void Student::setName(string Name)
{
    Name_ = Name;
}

void Student::setSurname(string Surname)
{
    Surname_ = Surname;
}

void Student::setHomework(vector <double> Homeworkl)
{
    Homework = Homeworkl;
}

void Student::setExam(int Examl)
{
    Exam = Examl;
}

int Student::getExam() const
{
    return Exam;
}

string Student::getName() const
{
    return Name_;
}

string Student::getSurname() const
{
    return Surname_;
}

double Student::getFinalAverange() const
{
    return FAverange;
}

double Student::getFinalMedian() const
{
    return FMedian;
}


Student& Student::operator=(const Student& s)
{
    if (&s == this)
        return *this;
    Name_ = s.getName();										//o cia antras budas nopijuoti
    Surname_ = s.getSurname();
    FMedian = s.getFinalMedian();
    FAverange = s.getFinalAverange();
    return *this;
}

bool Student::operator<(const Student& s2)
{
    if (Name_ != s2.getName())
        return Name_ < s2.getName();
    else
        return Surname_ < s2.getSurname();
}

bool Student::operator>(const Student& s2)
{
    if (Name_ != s2.getName())
        return Name_ > s2.getName();
    else
        return Surname_ > s2.getSurname();
}

bool Student::operator==(const Student& s2)
{
    if (Name_ == s2.getName() &&
            Surname_ == s2.getSurname() &&
            FMedian == s2.getFinalMedian() &&
            FAverange == s2.getFinalAverange())
    {
        return true;
    }
}

bool Student::operator!=(const Student& s2)
{
    if (Name_ != s2.getName() ||
            Surname_ != s2.getSurname() ||
            FMedian != s2.getFinalMedian() ||
            FAverange != s2.getFinalAverange())
    {
        return false;
    }


}

void Student::Calculation()
{

    sort(Homework.begin(), Homework.end());
    int position = Homework.size();

    if (position % 2 == 0)
    {
        Median = ((Homework.at(position / 2)) + (Homework.at(position / 2 - 1))) / 2;
    }
    else
    {
        Median = Homework.at(position / 2);
    }
    FMedian = (0.4 * Median) + (0.6 * Exam);

    for (int j = 0; j < Homework.size(); j++)
    {
        Averange += Homework.at(j);
    }
    Averange = Averange / Homework.size();
    FAverange = (0.4 * Averange) + (0.6 * Exam);
}

void GenerateFiles (std::size_t i)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval (1, 10), Amount(10, 20);

    int NumberOfStudents = i,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("File" + std::to_string(i) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" << j << " Pavarde" << j << " " << Interval(eng);
        std::vector <int> Results;
        std::vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << std::endl;
    }
    Write.close();
}

void Filereading (vector<Student>& Stud, string filename )
{

    std::ifstream in(filename);

    string a;
    int Homeworksum = 0;
    int l;
    Student Data;

    string Name, Surname;
    int exam;

    vector<double> Homework1;


    if (!in)
    {
        cout << "Duomenu failas neezistuoja" << endl;
        exit(0);
    }

    in >> a >> a >> a;
    while (a[0] == 'N')
    {
        Homeworksum++;
        in >> a;
    }

    while (!in.eof())
    {
        in >> Name >> Surname;

        Data.setName(Name);
        Data.setSurname(Surname);

        for (int i = 0; i < Homeworksum; i++)
            in >> l;

            Homework1.push_back(l);
        }
        in >> exam;
        Data.setExam(exam);

        Data.setHomework(Homework1);
        Stud.push_back(Data);
        Homework1.clear();


    in.close();

}

void DataImport(vector <Student>& Stud)
{

    int  n, l, exam, choice,k;
    string ka;
    string  Name, Surname;
    vector<double> Homeworkl;

    cout << "Kiek mokiniu bus?" << endl;
label1:
    cin >> k;
    if (k>0)
    {
        Student Data;
        for (int i = 0; i <k; i++)
        {
            cout << "Iveskite studento varda ir pavarde:" << endl;
            cin >> Name;
            Data.setName(Name);
            cin >> Surname;
            Data.setSurname(Surname);
            cout << "Ar norite jog rezultatai butu sugeneruoti atsitiktinai (1) ar norite irasyti pats/pati?(0)" << endl;
            cin >> choice;


            if (choice == 0)
            {
                cout << "Iveskite studento egzamino rezultata:" << endl;
label2:
                cin >> exam;
                if ( exam>0 and exam<11)
                    Data.setExam(exam);
                else
                {
                    cout << "Toks pasirinkimas negalimas, bandykite dar karta";
                    goto label2;
                }
                cout << "Iveskite studento namu darbu pazymiu skaiciu" << endl;
label3:
                cin >> n;
                if (exam>0)
                {
                    cout << "Iveskite pazymius " << endl;
                    for (int j = 0; j < n; j++)
                    {
label4:
                        cin >> l;
                        if ( l>0 and l<11)
                        {
                            Homeworkl.push_back(l);
                        }
                        else
                        {
                            cout << "Toks pasirinkimas negalimas, bandykite dar karta ";
                            goto label4;
                        }
                    }
                }
                else
                {
                    cout << "Toks pasirinkimas negalimas, bandykite dar karta";
                    goto label3;
                }
            }


            else if (choice == 1 )
            {
                srand(time(0));
                Data.setExam((1 + rand() % 10));		//egz pazymys generuojamas nuo 1 iki 10
                cout << "Iveskite studento namu darbu pazymiu skaiciu:" << endl;
                cin >> n;

                for (int j = 0; j < n; j++)
                {
                    l = (1 + rand() % 10);
                    Homeworkl.push_back(l);
                }
            }

        }
        Data.setHomework(Homeworkl);
        Stud.push_back(Data);
        Homeworkl.clear();
    }
    else
    {
        cout << "Bandykite dar karta" << endl;
        goto label1;
    }

}



void Calculations(vector <Student>& Stud)
{


    for (int i = 0; i < Stud.size(); i++)
    {

        Stud.at(i).Calculation();

    }
}





bool Failed1(Student& Stud)
{
    return (Stud.getFinalAverange() > 5);
}

bool Failed2(Student& Stud)
{
    return (Stud.getFinalMedian() > 5);
}

void GenerateOutputFiles (vector <Student>& Stud, vector <Student>& Failed, vector <Student>& Passed, int t)
{


    if (t == 0)
    {

        std::remove_copy_if(Stud.begin(), Stud.end(), std::back_inserter(Failed), Failed1);
        std::copy_if(Stud.begin(), Stud.end(), std::back_inserter(Passed), Failed1);

        Stud.erase(Stud.begin(), Stud.end());

    }

    else
    {

        std::remove_copy_if(Stud.begin(), Stud.end(), std::back_inserter(Failed), Failed2);
        std::copy_if(Stud.begin(), Stud.end(), std::back_inserter(Passed), Failed2);

        Stud.erase(Stud.begin(), Stud.end());
    }

}
void Print(vector <Student>& Stud, int t, string text)
{


    std::ofstream in(text);

    in << left << setw(25) << "Vardas:" << left << setw(30) << "Pavarde:";
    if (t == 1)
    {
        in << "Mediana" << endl;
    }
    else if (t == 2)
    {
        in << "Vidurkis" << " Mediana" << endl;
    }
    else
    {
        in << "Vidurkis" << endl;
    }

    for (int i = 0; i < Stud.size(); i++)
    {

        in << left << setw(25) << Stud.at(i).getName() << left << setw(30) << Stud.at(i).getSurname();
        if (t != 1)
        {
            in << left << setw(9) << setprecision(3) << Stud.at(i).getFinalAverange();
        }

        if (t != 0)
        {
            in << left << setw(9) << setprecision(2) << Stud.at(i).getFinalMedian();
        }

        in << endl;
    }
    in.close();

}

int Choice()
{
    std::string Entry;
    int EntryChoice;
    std::cout << "Kaip norite gauti stendentu duomenis?\n Spauskite:"
              "\n1, jeigu norite duomenis nuskaityti is failo 'kursiokai.txt',"
              "\n2, jeigu norite duomenis ivesti pats/pati"
              "\n3, jeigu norite skaityti duomenis is sugeneruotu failu" << std::endl;

    while (std::cin >> Entry)
    {
        if (Entry == "1")
        {
            EntryChoice = 1;
            break;
        }
        else if (Entry == "2")
        {
            EntryChoice = 2;
            break;
        }
        else if (Entry == "3")
        {
            EntryChoice = 3;
            break;
        }
        else
            std::cout << "Klaida" << std::endl;
    }
    std::cin.ignore();
    return EntryChoice;
}

