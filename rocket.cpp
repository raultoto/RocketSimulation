#include "rocket.h"
/*este es la distancia entre el centro de la tierra y el centro de gravedad
 * de nuestro cohete
*/
template<class T>
T get_velocidadascenso(T antheta,T V)
{
    cout<<"coseno"<<cos(antheta);
    return cos(antheta)*V;
}



/*Esto es un limite con el sonido
 * Se utilizara para el coeficiente de friccion
 * A un determinada velocidad varia el comportamiento del aire
*/
template<class T>
bool mach(T v,T velocitysoun)
{
    if(v/velocitysoun>1)
        return true;
    return false;
}

template<typename T>
Rocket<T>::Rocket()
{

}

///////desde aqui modifique//////////
template <typename T>
Rocket<T>::Rocket(T& altitud,T& vb1, T & latitud,T &longitud,T & dt)
    :height(altitud),vb(vb1),latitude(latitud),longitude(longitud),dt(dt)
{
    T temperatureb=121;
    T presionb=121;
    a=0;
    dough=200;
    height=211;//altitud
    area_nozzle=121;
    diameter=1212;//diametro maximo del cohete
    tip_length=121;
    vb=v;

     mytierra.set_var(altitud);
     velocity();
     theta=-mytierra.gravitynow*cos(theta)/v;
    A=diameter*diameter/4 * PI;
    update_var();
    ambiente.setvar(altitud);//T a,T pressureb1,T temperaturab1,T  hb1
}



/*
 * aceleracion
 * todavia falta variables por definir
*/

template<class T>
void Rocket<T>::acceleration()
{
    num_push=12;
    anguloataque=0;
    D=drag();

    mytierra.get_W(dough,r,phi);
    this->a=num_push*cos(anguloataque)/dough -D/dough-mytierra.Wr*cos(theta)/dough + mytierra.Wphi*sin(theta)*cos(azimut)/dough
    -pow(w,2)*r*cos(phi)*(sin(phi)*sin(theta)*cos(azimut)-cos(phi)*cos(theta));
    qDebug()<<a;
}

template<class T>
void Rocket<T>::velocity( )
{
    acceleration();
    T dv = a*dt;
    this->v=v+dv;
    T dvx=v*cos(theta);
    T dvy=v*cos(90-azimut);
    T dvz=v*cos(azimut);
    this->difvector_velocity.setX(dvx);
    this->difvector_velocity.setY(dvy);
    this->difvector_velocity.setZ(dvz);
    this->vector_velocity.setX(dvx+vector_velocity.getX() );
    this->vector_velocity.setX(dvy+vector_velocity.getY() );
    this->vector_velocity.setX(dvz+vector_velocity.getZ() );
    T dx=vector_velocity.getX();
    T dy=vector_velocity.getY();
    T dz=vector_velocity.getZ();
    this->posicion.setX(posicion.getX()+dx);
    this->posicion.setY(posicion.getY()+dy);
    this->posicion.setZ(posicion.getZ()+dz);
    cout<<"la velocidad es igual"<<vector_velocity.getX()<<" "<<vector_velocity.getY()<<" "<<vector_velocity.getZ()<<"  "<<endl;
    cout<<"posicion"<<posicion.getX()<<" "<<posicion.getY()<<" "<<posicion.getZ()<<"  "<<endl;

}


template<class T>
T Rocket<T>::get_velocidad_ascenso()
{
    T vascenso=v*cos(theta);
    return vascenso;
}



template<class T>
void Rocket<T> :: setlatitud_longitud(T & latitud,T & longitud,T & altitud)
{
this->latitude= latitud;
this->longitude=longitud;
    velocity();
    //radio_vector=get_radio_vector(theta,v);
    ambiente.setvar(altitud);
    mytierra.set_var(altitud);
    update_var();
}

template<class T>
void Rocket<T>::get_cdycl()
{
    T divide =tip_length/diameter;
    ambiente.getspeedsound();
    T numMatch=mach(v,ambiente.speedsound);
    //coeficiente de arrastre se divide en 3 coeficientre de onda ,coeficiente base y coeficiente friccion
    T cdf=0.53*(divide)*pow(dough/ q *tip_length,0.2);//coeficiente de friccion por la forma del cuerpo
    T cdo=0;
    T cdb=0.12+0.13*pow(dough,2);

    if(numMatch>=1 )
    {   if(divide<25 && divide>5)///que pasa en los casos cuando no esta en estos parametros
            cdo=(1586+1834/pow(dough,2))*pow(1/(tan(0.5/divide)) ,1.69);
        cdb=0.25/numMatch;
        this->Cd=cdf+cdo+cdb;
    }

    else
        this->Cd=cdf+cdb;
    this->Cl=0.53*(sin(2*anguloataque)*cos(anguloataque/2))+(divide)* pow(sin(anguloataque),2);
}


template<class T>
void Rocket<T> :: update_var()
{
   // vectores<T> vax=j.escalar(radio_vector * velocidadangulo.getZ(),j) + k.escalar(radio_vector*velocidadangulo.getZ(),k) ;
   // mytierra.set_altitude(altitud);
    T vay=(-v*sin(theta)*cos(azimut))/mytierra.radio_vector ;
    T vaz=(v*sin(theta)*sin(azimut))/mytierra.radio_vector ;
    velocidadangulo.setY(vay);
    velocidadangulo.setZ(vaz);
    velocidadangulo.setX(vaz);
    q=1/2*v*v*ambiente.airDensity;///presion dinamica q

    ///hallando arrastre coeficientes de arrastre y sustentacion
    get_cdycl();
    this->phi=v*sin(theta)*cos(azimut)/r ;
    this->lamnda=v*sin(theta)*sin(azimut)/r*cos(phi);
}
///////hasta aqui//////////
template<class T>
T Rocket<T> :: push()
{
    this->num_push=dough*velocityout + A*(pressuergases-ambiente.getpresionbyLm() );
    return num_push;
}

template<class T>
T Rocket<T> :: lift()
{
    return 1/2*ambiente.airDensity*pow(v,2)*A*Cl;
}

template<class T>
T Rocket<T>::gravity()
{
    return 55;
}

template<class T>
T Rocket<T>::drag()
{
    get_cdycl();
    this->D=1/2*ambiente.airDensity*pow(v,2)*A;//*Cd;
   // cout<<"Arrastres ="<<D;
    return D;
}

template<class T>
T Rocket<T>::getdough()
{
    return this->dough;
}

template<class T>
T Rocket<T>:: getheight()
{
    return this->height;
}

template<class T>
T Rocket<T>:: getareaall()
{
    return this->area_all;
}

template<class T>
T Rocket<T>:: getarea_nozzle()
{
    return this->area_nozzle;
}

