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
 * Se utilizara para el coeiciente de riccion
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

///////desde aqui modiique//////////
template <typename T>
Rocket<T>::Rocket(T& altitud,T& vb, T & latitud,T &longitud,T & dt)
    :height(altitud),v(vb),latitude(latitud),longitude(longitud),dt(dt),vb(vb)
{
    a=0;
    area_nozzle=121;
    diameter=212;//diametro maximo del cohete
    tip_length=121;
    ambiente.setvar(altitud);
    mytierra.set_var(altitud);
    A=diameter*diameter/4 * PI;
    update_var();
    ambiente.setvar(altitud);//T a,T pressureb1,T temperaturab1,T  hb1
}

template<class T>
void Rocket<T> :: setlatitud_longitud(T & latitud,T & longitud,T & altitud)
{
    this->latitude= latitud;
    this->longitude=longitud;
    //radio_vector=get_radio_vector(theta,v);
    ambiente.setvar(altitud);
    mytierra.set_var(altitud);
    update_var();
   // cout<<"densidad"<<ambiente.getdensitybyLm();
    //cout<<"tpq="<<q;
}

template<class T>
void Rocket<T> :: update_var()
{
    dough=20;//masa cambiable
    ///hallando arrastre coeicientes de arrastre y sustentacion
    theta=-mytierra.gravitynow*cos(theta)/v;
    q=(1.0/2.0)*ambiente.getdensitybyLm()*vb*vb;
    get_cdycl();
    this->phi=(v*sin(theta)*cos(azimut))/r ;
    this->lamnda=(v*sin(theta)*sin(azimut))/r*cos(phi);
}


/*
 * aceleracion
 * todavia alta variables por deinir
*/

template<class T>
void Rocket<T>::acceleration()
{
    D=drag();
    r=2;
    phi=37;
     anguloataque=12;
    cout<<"phi!"<<phi;
    //aptualizo w
    mytierra.get_W(dough,r,phi);
    this->a=num_push*cos(anguloataque)/dough -D/dough-mytierra.Wr*cos(theta)/dough + mytierra.Wphi*sin(theta)*cos(azimut)/dough
    -pow(w,2)*r*cos(phi)*(sin(phi)*sin(theta)*cos(azimut)-cos(phi)*cos(theta));
    cout<<"ACELERACION"<<num_push*cos(anguloataque)/dough-D ;
}


template<class T>
T Rocket<T> :: dif_velocity()
{
    return this->dv;
}

template<class T>
void Rocket<T>::velocity()
{
    acceleration();
    dv = a*dt;
    this->v=v+dv;

    T dvx=v*cos(theta);
    T dvy=v*cos(90-azimut);
    T dvz=v*cos(azimut);

    this->vector_velocity.setX(dvx+vector_velocity.getX() );
    this->vector_velocity.setY(dvy+vector_velocity.getY() );
    this->vector_velocity.setZ(dvz+vector_velocity.getZ() );
}

template<typename T>
void Rocket<T>::position()
{
    T dx=vector_velocity.getX()*dt;
    T dy=vector_velocity.getY()*dt;
    T dz=vector_velocity.getZ()*dt;
    this->posicion.setX(posicion.getX()+dx);
    this->posicion.setY(posicion.getY()+dy);
    this->posicion.setZ(posicion.getZ()+dz);
}

template<typename T>
void Rocket<T>::movimiento()
{
    acceleration();
    velocity();
    position();
}

//r
template<class T>
T Rocket<T>::get_velocidad_ascenso()
{
    T vascenso=v*cos(theta);
    return vascenso;
}

template<class T>
void Rocket<T>::get_cdycl()
{
    ///presion dinamica q=S
    T divide =tip_length/diameter;
    //ambiente.getspeedsound();
    T numMatch=mach(v,ambiente.speedsound);
    cout<<"densidad de Lm"<<ambiente.getdensitybyLm()<<endl;
    q=(1.0/2.0)*ambiente.getdensitybyLm()*vb*vb;
    cout<<"q"<<ambiente.getdensitybyLm();
    cout<<dough/q*tip_length;
    //coeiciente de arrastre se divide en 3 coeicientre de onda ,coeiciente base y coeiciente riccion
    T cd=0.53*(divide)*pow(dough/q*tip_length,0.2);//coeiciente de riccion por la orma del cuerpo
    T cdo=0;
    T cdb=0.12+0.13*pow(dough,2);

    if(numMatch)
    {   if(divide<25 && divide>5)///que pasa en los casos cuando no esta en estos parametros
            cdo=(1586+1834/pow(dough,2))*pow(1/(tan(0.5/divide)) ,1.69);
        cdb=0.25/numMatch;
        this->Cd=cd+cdo+cdb;
    }
    else
        this->Cd=cd+cdb;
    this->Cl=0.53*(sin(2*anguloataque)*cos(anguloataque/2))+(divide)* pow(sin(anguloataque),2);
}


///////hasta aqui//////////
template<class T>
T Rocket<T> :: push()
{///A=area de la tobera
    this->num_push=dough*velocityout + A*(pressuergases-ambiente.getpresionbyLm() );
    return num_push;
}

template<class T>
T Rocket<T> :: lift()
{
    return 1/2*ambiente.airDensity*pow(v,2)*A*Cl;
}
/*
template<class T>
T Rocket<T>::gravity()
{
    return 55;
}*/
///////////////////////////////////////nan
template<class T>
T Rocket<T>::drag()
{
    get_cdycl();
    this->D=1/2*ambiente.airDensityb*pow(v,2)*A*Cd;
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

