#ifndef NOMBRE_HPP_INCLUDED
#define NOMBRE_HPP_INCLUDED

#include<string>
#include<iostream>
#include<cstdio>

class Nombre{
private:

    std::string nombre;
    std::string app;
    std::string apm;


public:
    Nombre();
    Nombre(const Nombre&);

    std::string getNombre()const;
    std::string getApp() const;
    std::string getApm() const;

    std::string toString() const;

    void setNombre(const std::string&);
    void setApp(const std::string&);
    void setApm(const std::string&);


    Nombre& operator=(const Nombre&);

    bool operator ==(const Nombre&) const;
    bool operator !=(const Nombre&) const;
    bool operator <(const Nombre&) const;
    bool operator <=(const Nombre&) const;
    bool operator >(const Nombre&) const;
    bool operator >=(const Nombre&) const;

    friend std::ostream& operator <<(std::ostream&, const Nombre&);
    friend std::istream& operator >>(std::istream&, Nombre&);




};

#endif // NOMBRE_HPP_INCLUDED
