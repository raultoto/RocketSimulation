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


///
///tall=1.0;comienza a partir el cohete desde 1s
template <typename T>
Rocket<T>::Rocket(T& altitud,T& vb, T & latitud,T &longitud,T & dt)
    :height(altitud),v(vb),phi(latitud),lamnda(longitud),dt(dt),vb(vb),tall(1)
{
    dough=121;
    a=0;
    w=1;
   // diameter=212;//diametro maximo del cohete
    tip_length=121;
    ambiente.setvar(altitud);
    mytierra.set_var(altitud);
    //A=diameter*diameter/4 * PI;
    update_var();
    theta=0;
    r=mytierra.r_mediotierra+altitud;
}

template<class T>
void Rocket<T> :: setlatitud_longitud(T & latitud,T & longitud,T & altitud,T v1)
{
    height=altitud;
    v=v1;
    tall=tall + dt;
    phi= latitud;
    this->lamnda=longitud;
    ambiente.setvar(altitud);
    mytierra.set_var(altitud);
    update_var();
    r=mytierra.r_mediotierra+altitud;
}

template<class T>
void Rocket<T> :: update_var()
{

    azimut=0;
    //theta=20;
    dough=120;//masa cambiable
    ///hallando arrastre coeicientes de arrastre y sustentacion
    ////theta=-mytierra.gravitynow*cos(theta)/v;
    q=(1.0/2.0)*ambiente.getdensitybyLm()*vb*vb;
    get_cdycl();
    this->phi=(v*sin(theta)*cos(azimut))/r ;
    this->lamnda=(v*sin(theta)*sin(azimut))/r*cos(phi);
    this->Push =push();
    this->L = lift();
    mytierra.get_W(dough,r,phi);
    this->wr =mytierra.get_wr();
    this->wphi =mytierra.get_wphi();
}

///lo mas importante funcion

template<class T>
T Rocket<T> :: dif_altitud()
{
   T daltitudg=ambiente.dif_altitud();
   return daltitudg;
}

template<class T>
T Rocket<T> :: dif_phi()
{
   return (v*sin(theta)*cos(azimut) )/r;
}

template<class T>
T Rocket<T> :: dif_lamnda()
{
    return (v*sin(theta)*sin(azimut) )/(r*cos(phi));
}

template<class T>
T Rocket<T> :: dif_theta()
{
    return  (Push*sin(anguloataque))/dough*v + L/dough*v + (wr*sin(theta))/dough*v -2*w*sin(azimut)*cos(phi)
            +(wphi*cos(theta)*cos(azimut))/dough*v-v/r*sin(theta)
            -(pow(w,2)*r*cos(phi))/v*(sin(phi)*cos(theta)*cos(azimut)
              +cos(phi)*sin(theta));
}

//ecuacion(61)
template<class T>
T Rocket<T> :: dif_azimut()
{
    return (w*w*r*sin(azimut)*sin(phi)*cos(theta))/v*sin(theta)
            +(v/r)*sin(theta)*sin(azimut)*tan(phi)
            -(wphi*sin(azimut))/dough*v -2*w/sin(sin(theta))*
            (cos(phi)*cos(theta)*cos(azimut) -sin(phi)*sin(theta));
}
/*
 * aceleracion
 * todavia alta variables por deinir
*/

template<class T>
void Rocket<T>::aceleration()
{
    D=drag();
    cout<<"phi!"<<phi;
    cout<<"drag!"<<D;
    cout<<"psuh!"<<Push;
    //aptualizo w
    this->a=Push*cos(anguloataque)/dough -D/dough-mytierra.wr*cos(theta)/dough + mytierra.wphi*sin(theta)*cos(azimut)/dough
    -pow(w,2)*r*cos(phi)*(sin(phi)*sin(theta)*cos(azimut)-cos(phi)*cos(theta));
    this->a=a*1/1000000000000000000000000000000000000000000000000000000000000;
    cout<<"ACELERACION"<<a<<"phi"<<phi<<" lambda "<<lamnda<<"theta"<< theta <<endl;
}


template<class T>
vectores<T> Rocket<T>::dif_velocity()
{
    cout<<"V"<<v;
    dv = a*dt;
    cout<<"fiferencial de la velocidad"<<dv<<" v"<<v;
    v=v+dv;
    cout<<"v es igual a"<<v;
    ///////convertir el vector v en x,y,z
    vectores<T> dv;
    dv.setX(v*cos(theta));
    dv.setY(v*cos(90-azimut));
    dv.setZ(v*cos(azimut));
    return dv;
/*
    this->vector_velocity.setX(dvx+vector_velocity.getX() );
    this->vector_velocity.setY(dvy+vector_velocity.getY() );
    this->vector_velocity.setZ(dvz+vector_velocity.getZ() );*/
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
T Rocket<T>::get_tall()
{
    return tall;
}
/*template<typename T>
void Rocket<T>::movimiento()
{
    aceleration();
    dif_velocity();
    position();
}*/

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


///////integral ecuacion2//////////
template<class T>
T Rocket<T> :: push()
{
    cout<<"tall!!"<<this->tall<<"termino";
    cout<<"push!!!!!!!"<<(dough_expel*velocity_expel)/tall;
    if(dough_expel*tall<=dough_tobera)
    {   this->Push=(dough_expel*velocity_expel)/tall;
        return Push;
    }
    else
        return 0;
    return -10000000;
}

template<class T>
T Rocket<T> ::dif_dought()
{
    return dough_expel*tall;;
}

template<class T>
T Rocket<T> :: lift()
{
    return 1/2*ambiente.airDensityb*pow(v,2)*A*Cl;
}

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

///sacando la latitud
template<class T>
T Rocket<T>::get_phi()
{
    return phi;
}

///sacacndo la longitud
template<class T>
T Rocket<T>::get_lamnda()
{
    return lamnda;
}
