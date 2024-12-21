#include <iostream>
#include <iomanip>
#include "ArchivoPagos.h"

using namespace std;

ArchivoPagos::ArchivoPagos() {}

ArchivoPagos::ArchivoPagos(std::string nombreArchivo)
{
	_nombreArchivo = nombreArchivo;
}

bool ArchivoPagos::guardarReg(Pago& pago)
{
	bool guardado;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	guardado = fwrite(&pago, sizeof(Pago), 1, pfile);
	fclose(pfile);

	return guardado;
}

Pago ArchivoPagos::leerReg(int pos)
{
	Pago pago;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return pago; }

	fseek(pfile, sizeof(Pago) * pos, SEEK_SET);
	fread(&pago, sizeof(Pago), 1, pfile);
	fclose(pfile);

	return pago;
}

bool ArchivoPagos::modificarReg(Pago& pago, int pos)
{
	bool modificado;
	FILE* pfile;

	pfile = fopen(_nombreArchivo.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Pago) * pos, SEEK_SET);
	modificado = fwrite(&pago, sizeof(Pago), 1, pfile);
	fclose(pfile);

	return modificado;
}

int ArchivoPagos::buscarReg(int id)
{
	Pago pago;
	int pos = 0;

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	while (fread(&pago, sizeof(Pago), 1, pfile) == 1)
	{
		if (pago.getIdUsuario() == id)
		{
			fclose(pfile);
			return pos;
		}
		pos++;
	}

	fclose(pfile);
	return -2;

	//if (pago.getIdUsuario() == id)
	//{
	//	return pos;
	//}
	//else
	//{
	//	return -1;
	//}
}

int ArchivoPagos::cantidadRegistros()
{
	int cantReg;
	Pago pago;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return 0; }

	fseek(pfile, 0, SEEK_END);
	cantReg = ftell(pfile);
	fclose(pfile);

	return cantReg / sizeof(Pago);
}

void ArchivoPagos::leerRegistros(int cantPagos, Pago* pagos)
{
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return; }

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&pagos[i], sizeof(Pago), 1, pfile);
	}

	fclose(pfile);
} 


int ArchivoPagos::cantidadPagosPorSocio(int cantPagos, int idUsuario) //creo que tengo que agregar un vector de pagos por parametro
{
	Pago pago;
	int cont = 0;

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&pago, sizeof(Pago), 1, pfile); //siempre lee el mismo pago //esto esta mal
		if (pago.getIdUsuario() == idUsuario)
		{
			cont++;
		}
	}

	fclose(pfile);
	return cont;
}

int ArchivoPagos::leerPagosPorSocio(int cantPagos, int pagosPorSocio[], int idUsuario)
{
	Pago pago;
	int index = 0;

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&pago, sizeof(Pago), 1, pfile);
		if (pago.getIdUsuario() == idUsuario)
		{
			pagosPorSocio[index] = i;
			index++;
		}
	}

	fclose(pfile);
	return *pagosPorSocio;
}

int ArchivoPagos::ultimoPagoSocio(int cantPagos, int idUsuario)
{
	Pago pago; 
	int pos = -1;
	FILE* pArchivo;
	pArchivo = fopen(_nombreArchivo.c_str(), "rb");

	if (pArchivo == nullptr) { return -1; }

	for (int i = 0; i < cantPagos; i++) 
	{
		fread(&pago, sizeof(Pago), 1, pArchivo);
		if (pago.getIdUsuario() == idUsuario)
		{
			pos = i; // el for va a dar x vueltas y en cada vuelta si encuentra una coincidencia la guarda, pisando la anterior
		}
	}

	fclose(pArchivo);
	return pos;
}


void ArchivoPagos::crearPago()
{
	int idUsuario, dia, mes, anio;
	float monto;
	//Fecha fechaPeriodo;
	Fecha periodo;
	Fecha fechaPago;

	cout << "Ingresa usuario: ";
	cin >> idUsuario;
	cout << "Ingresa monto: ";
	cin >> monto;
	cout << "Ingresa el mes del periodo: ";
	cin >> mes;
	periodo.setMes(mes);
	cout << "Ingresa el anio del periodo: ";
	cin >> anio;
	periodo.setAnio(anio);

	cout << "Ingresa dia de pago: ";
	cin >> dia;
	fechaPago.setDia(dia);
	cout << "Ingresa mes de pago: ";
	cin >> mes;
	fechaPago.setMes(mes);
	cout << "Ingresa anio de pago: ";
	cin >> anio;
	fechaPago.setAnio(anio);

	Pago pago(idUsuario, monto, periodo, fechaPago);
	guardarReg(pago);
}

void ArchivoPagos::mostrarPago(Pago pago)
{
	cout << string(105, '-') << endl;
	cout << left << setw(5) << "ID usuario" << "|"
		<< setw(13) << "Monto" << "|"
		<< setw(12) << "Periodo" << "|"
		<< setw(14) << "Fecha pago" << "|" << endl;
	cout << string(105, '-') << endl;


	cout << left << setw(5) << pago.getIdUsuario() << "|"
		<< setw(13) << pago.getMonto() << "|"
		<< setw(12) << pago.getPeriodo().toString() << "|"
		<< setw(14) << pago.getFechaPago().toString() << "|" << endl;
	cout << string(105, '-') << endl;

	//for (int i = 0; i < cantReg; i++)
	//{
		//socio = socios[i];
		////cout << string(78, '-') << endl;
		//cout << left << setw(5) << socio.getIdUsuario() << "|"
		//	<< setw(13) << socio.getApellido() << "|"
		//	<< setw(12) << socio.getNombre() << "|"
		//	<< setw(14) << socio.getFechaIngreso().toString() << "|"
		//	<< setw(45) << membresiaToStr(socio.getMembresia()).c_str() << "|"
		//	<< setw(20) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
		//cout << string(105, '-') << endl;
	//}
	//system("pause");
}

void ArchivoPagos::mostrarPago()
{
	Pago pago = leerReg(0);
	cout << string(105, '-') << endl;
	cout << left << setw(14) << "ID Usuario" << "|"
		<< setw(13) << "Monto" << "|"
		<< setw(12) << "Periodo" << "|"
		<< setw(14) << "Fecha pago" << "|" << endl;
	cout << string(105, '-') << endl;


	cout << left << setw(14) << pago.getIdUsuario() << "|"
		<< setw(13) << pago.getMonto() << "|"
		<< setw(12) << pago.getPeriodo().toString() << "|"
		<< setw(14) << pago.getFechaPago().toString() << "|" << endl;
	cout << string(105, '-') << endl;
}

void ArchivoPagos::mostrarTodos()
{
	Pago pago;
	Pago* pagos;
	int cantReg = cantidadRegistros();

	pagos = new Pago[cantReg];
	if (pagos == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
		system("pause");
	}

	//for (int i = 0; i < cantReg; i++)
	//{
	//	pagos[i] = leerReg(i);
	//}

	leerRegistros(cantReg, pagos);

	for (int i = 0; i < cantReg; i++)
	{
		mostrarPago(pagos[i]);
	}

	//cout << string(105, '-') << endl;
	//cout << left << setw(5) << "ID usuario" << "|"
	//	<< setw(13) << "Monto" << "|"
	//	<< setw(12) << "Periodo" << "|"
	//	<< setw(14) << "Fecha pago" << "|" << endl;
	//cout << string(105, '-') << endl;
	//
	//for (int i = 0; i < cantReg; i++)
	//{
	//	pago = pagos[i];
	//	cout << left << setw(5) << pago.getIdUsuario() << "|"
	//		<< setw(13) << pago.getMonto() << "|"
	//		<< setw(12) << pago.getPeriodo().toString() << "|"
	//		<< setw(14) << pago.getFechaPago().toString() << "|" << endl;
	//	cout << string(105, '-') << endl;
	//}


	delete[]pagos;
	system("pause");
}

void ArchivoPagos::pagosDelSocio()
{
	Pago pago;
	int cantPagos = cantidadRegistros();
	int cantPagosSocio = cantidadPagosPorSocio(cantPagos, 1);

	int* pagosPorSocio;
	pagosPorSocio = new int[cantPagosSocio];
	if (pagosPorSocio == nullptr) { return; }
	
	*pagosPorSocio = leerPagosPorSocio(cantPagos, pagosPorSocio, 1);

	if (cantPagosSocio > 0)
	{
		for (int i = 0; i < cantPagosSocio; i++)
		{
			pago = leerReg(pagosPorSocio[i]);

			cout << "+--------------------------+" << endl;
			cout << "| ID #" << pago.getIdUsuario() << endl;
			cout << "| Fecha de pago: " << pago.getFechaPago().toString() << endl;
			cout << "| Monto: $" << pago.getMonto() << endl;
			cout << "+--------------------------+" << endl;
		}
	}
	else
	{
		cout << "+-------------------------+" << endl;
		cout << "|  No se registran pagos  |" << endl;
		cout << "+-------------------------+" << endl;
	}

	delete[]pagosPorSocio;
	system("pause");
}