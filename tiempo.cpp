#include "tiempo.hpp"

using namespace std;

int Tiempo::toInt() const {
    return hora*100+minutos;
    }

bool Tiempo::isValid(const int& h, const int& m) {
    return h>=0 and h<24 and m>=0 and m<60;
    }


Tiempo::Tiempo() {
    chrono::system_clock::time_point today=chrono::system_clock::now();
    time_t tt;
    tt=chrono::system_clock::to_time_t(today);
    struct tm* timeinfo;
    timeinfo=localtime(&tt);

    hora=timeinfo->tm_hour;
    minutos=timeinfo->tm_min;
    }

Tiempo::Tiempo(const Tiempo& t) :hora(t.hora), minutos(t.minutos) {}


Tiempo::Tiempo(const int& h, const int& m) : Tiempo() {
    if(isValid(h,m)) {
        hora=h;
        minutos=m;
        }
    }

int Tiempo::getHora() const {
    return hora;
    }

int Tiempo::getMinutos() const {
    return minutos;
    }

string Tiempo::toString() const {
    char myStr[4];
    sprintf(myStr,"%02i:%02i",hora,minutos);
    return myStr;

    }

void Tiempo::setHora(const int& h) {

    if(isValid(h,minutos)) {
        hora=h;
        }

    }

void Tiempo::setMinutos(const int& m) {

    if(isValid(hora, m)) {
        minutos=m;
        }


    }

Tiempo& Tiempo::operator=(const Tiempo& t) {
    hora=t.hora;
    minutos=t.minutos;

    return *this;
    }

bool Tiempo::operator==(const Tiempo& t) const {
    return toInt()==t.toInt();
    }

bool Tiempo::operator!=(const Tiempo& t) const {
    return toInt()!=t.toInt();
    }

bool Tiempo::operator<(const Tiempo& t) const {
    return toInt()<t.toInt();
    }

bool Tiempo::operator<=(const Tiempo& t) const {
    return toInt()<=t.toInt();
    }

bool Tiempo::operator>(const Tiempo& t) const {
    return toInt()>t.toInt();
    }

bool Tiempo::operator>=(const Tiempo& t) const {
    return toInt()>=t.toInt();
    }

ostream& operator<<(ostream& os, const Tiempo& t) {
    os<<t.toString();

    return os;

    }

istream& operator >> (istream& is, Tiempo& t) {
    string mystr;

    getline(is, mystr, ':');
    t.hora = atoi(mystr.c_str());

    getline(is,mystr);
    t.minutos = atoi(mystr.c_str());


    return is;
    }


