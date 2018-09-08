/*Funcion de activacion P. Evalua la entrada y la satura a valores mayores a 1 y menores a -1*/
float neuroP(float in)
{
	if(in<-1)
		return -1;
	else if(in>1)
		return 1;
	else 
		return in;
}

/*Funcion de activacion I. Suma la salida anterior con la entrada y la satura usando la funcion P*/
float neuroI(float out_anterior, float in)
{
	return neuroP(out_anterior+in);
}
/*Funcion de activacion D. Calcula la diferencia entre la entrada actual y la anterior y la satura usando la funcion P*/
float neuroD(float in_anterior, float in)
{
	return neuroP(in-in_anterior);
}
