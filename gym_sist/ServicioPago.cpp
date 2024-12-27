#include <iostream>
#include <iomanip>
#include "Pago.h"
#include "ServicioSocio.h"
#include "ServicioPago.h"
#include "ArchivoPagos.h"

using namespace std;

ServicioPago::ServicioPago()
{
	_archivoPago = ArchivoPagos("archivoPago.dat");
}

bool ServicioPago::verificarUltimoPago(int idSocio)
{
	Pago pago;
	Fecha fechaActual;

	int cantPagos = _archivoPago.cantidadRegistros();
	int pos = _archivoPago.ultimoPagoSocio(cantPagos, idSocio);

	if (pos != -1)
	{
		pago = _archivoPago.leerReg(pos);
		if (pago.getPeriodo().getMes() + 1 == fechaActual.getMes())
		{
			return true;
		}
		else if (pago.getPeriodo().getMes() == fechaActual.getMes())
		{
			return true;
		}
		else if (pago.getPeriodo().getDia() + 30 > 30 && pago.getPeriodo().getDia() + 30 < 41)
		{
			return true;
		}
	}
	return false;
}

bool ServicioPago::registrarPago(int idSocio, int idPase, Fecha periodo)
{
	system("cls");

	Fecha fechaActual;
	float monto;
	int opc;

	if (verificarUltimoPago(idSocio))
	{
		cout << " +-----------------------+" << endl;
		cout << " |   No presenta deuda   |" << endl;
		cout << " +-----------------------+" << endl;
		cout << " " << endl;
		system("pause");
		return false;
	}

	int mes = fechaActual.getMes(); // corregir como calcula fecha. si yo pago el mes de dicimebre en diciembre no me lo esta tomando
	periodo.setMes(mes + 1);

	cout << "+-----------------------+" << endl;
	cout << "|   PAGAR MENSUALIDAD   |" << endl;
	cout << "+-----------------------+" << endl;

	cout << "  Pase actual : " << endl;
	switch (idPase)
	{
	case 0:
		cout << "  Corro media cuadra y necesito respirador : $ 25.000" << endl;
		break;
	case 1:
		cout << "  Me hago unas dominadas                   : $ 35.000" << endl;
		break;
	case 2:
		cout << "  Soy el hijo de Swarzenneger              : $ 40.000" << endl;
		break;
	}

	cout << endl;
	cout << "  1. Confirmar pago " << endl;
	cout << "  2. Cambiar de pase? " << endl;
	cout << endl;
	cout << "  Su seleccion: ";
	cin >> opc;

	if (opc == 2)
	{
		cout << "  Pases disponibles: " << endl;
		cout << endl;
		cout << "  0. Corro media cuadra y necesito respirador : $ 25.000 - " << endl;
		cout << "  1. Me hago unas dominadas                   : $ 35.000 - " << endl;
		cout << "  2. Soy el hijo de Swarzenneger              : $ 40.000 - " << endl;
		cout << endl;
		cout << "  Su selecionn: " << endl;
		cin >> idPase;
	}

	switch (idPase)
	{
	case 0:
		monto = 25000;
		break;
	case 1:
		monto = 30000;
		break;
	case 2:
		monto = 45000;
		break;
	}

	Pago pago(idSocio, monto, periodo, fechaActual);

	if (_archivoPago.guardarReg(pago))
	{
		system("cls");
		cout << "+-------------------------------------------------+" << endl;
		cout << "|         --- Pago realizado con exito ---        |" << endl;
		cout << "|     Proxima fecha de vencimiendo: " << periodo.toString() << "     |" << endl;
		cout << "+-------------------------------------------------+" << endl;
		return true;
	}
	else
	{
		system("cls");
		cout << "+------------------------------------------------------------------+" << endl;
		cout << "|      --- Su pago no se pudo realizar, prueba mas tarde ---		|" << endl;
		cout << "+------------------------------------------------------------------+" << endl;
		return false;
	}
}

void ServicioPago::verPagosPorSocio(int idSocio)
{
	system("cls");

	Pago pago;
	int cantPagos = _archivoPago.cantidadRegistros();
	int cantPagosSocio = _archivoPago.cantidadPagosPorSocio(cantPagos, idSocio);

	int* pagosPorSocio;
	pagosPorSocio = new int[cantPagosSocio];
	if (pagosPorSocio == nullptr) { return; }

	*pagosPorSocio = _archivoPago.leerPagosPorSocio(cantPagos, pagosPorSocio, idSocio);

	if (cantPagosSocio > 0)
	{
		for (int i = 0; i < cantPagosSocio; i++)
		{
			pago = _archivoPago.leerReg(pagosPorSocio[i]);
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

	// traer cantidades
	// asignar memoria dinamica a el vector
	// llenar el vector
	// ciclar el vector para leerlo 
	// mostrar info
}

void ServicioPago::verPagosPorMes()
{
	system("cls");
	Pago pago;
	int mes, anio, contador = 0;

	cout << "   +-------------------------+" << endl;
	cout << "   |      PAGOS POR MES      |" << endl;
	cout << "   +-------------------------+" << endl;
	cout << endl;
	cout << "   Ingresa un mes: " << endl;
	cin >> mes;
	cout << "   Ingresa un anio: " << endl;
	cin >> anio;

	int cantPagos = _archivoPago.cantidadRegistros();

	for (int i = 0; i < cantPagos; i++)
	{
		pago = _archivoPago.leerReg(i);
		if (pago.getFechaPago().getMes() == mes && pago.getFechaPago().getAnio() == anio)
		{
			cout << "   +----------------------------+" << endl;
			cout << "   | Fecha de pago: " << pago.getFechaPago().toString() << endl;
			cout << "   | ID#          : " << pago.getIdUsuario() << endl;
			cout << "   | Monto        : $ " << pago.getMonto() << endl;
			cout << "   +----------------------------+" << endl;
		}
		contador++;
		if (contador % 10 == 0)
		{
			cout << "  Siguiente pagina..." << endl;
			system("pause");
			system("cls");

			contador = 0;
		}
	}
	if (contador == 0)
	{
		cout << "   +---------------------------------------------------------+" << endl;
		cout << "   |   No se registraron pagos en el mes y anio ingresados   |" << endl;
		cout << "   +---------------------------------------------------------+" << endl;
	}
}

void ServicioPago::verPagosPorAnio()
{
	system("cls");

	Pago pago;
	int anio, contador = 0;

	cout << "   +--------------------------+" << endl;
	cout << "   |      PAGOS POR ANIO      |" << endl;
	cout << "   +--------------------------+" << endl;
	cout << endl;

	cout << "  Ingresa el anio" << endl;
	cin >> anio;

	int cantPagos = _archivoPago.cantidadRegistros();
	for (int i = 0; i < cantPagos; i++)
	{
		pago = _archivoPago.leerReg(i);
		if (pago.getFechaPago().getAnio() == anio)
		{
			cout << "   +----------------------------+" << endl;
			cout << "   | Fecha de pago: " << pago.getFechaPago().toString() << endl;
			cout << "   | ID #         : " << pago.getIdUsuario() << endl;
			cout << "   | Monto        : $ " << pago.getMonto() << endl;
			cout << "   +----------------------------+" << endl;
		}
		contador++;

		if (contador % 10 == 0)
		{
			cout << "  Siguiente pagina... " << endl;
			system("pause");
			system("cls");

			contador = 0;
		}
	}

	if (contador == 0)
	{
		cout << endl;
		cout << "   +--------------------------------------------------+" << endl;
		cout << "   |   No se registragon pagos en el anio ingresado   |" << endl;
		cout << "   +--------------------------------------------------+" << endl;

		contador = 0;
	}


}

void ServicioPago::verIngresosAnuales()
{
	system("cls");

	Pago pago;
	float ingresoPorMes[12] = {};
	float montoTotal = 0;
	int anio;

	cout << "   +----------------------------+" << endl;
	cout << "   |      INGRESOS ANUALES      |" << endl;
	cout << "   +----------------------------+" << endl;
	cout << endl;
	cout << " Ingrese anio de consulta: ";
	cin >> anio;

	int cantPagos = _archivoPago.cantidadRegistros();

	if (cantPagos > 0)
	{
		for (int i = 0; i < cantPagos; i++)
		{
			pago = _archivoPago.leerReg(i);

			if (pago.getFechaPago().getAnio() == anio)
			{
				ingresoPorMes[pago.getFechaPago().getMes() - 1] += pago.getMonto();
				montoTotal += pago.getMonto();
			}
		}
	}
	else
	{
		cout << endl;
		cout << "   +--------------------------------------------------+" << endl;
		cout << "   |   No se registragon pagos en el anio ingresado   |" << endl;
		cout << "   +--------------------------------------------------+" << endl;
	}

	cout << endl;
	cout << "   +--------------------------------------------------+" << endl;
	cout << "   |   MES                 ||             INGRESOS    |" << endl;
	cout << "   +--------------------------------------------------+" << endl;

	for (int b = 0; b < 12; b++)
	{
		if (ingresoPorMes[b] != 0)
		{
			switch (b)
			{
			case 0:
				cout << "   ENERO            ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 1:
				cout << "   FEBRERO          ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 2:
				cout << "   MARZO            ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 3:
				cout << "   ABRIL            ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 4:
				cout << "   MAYO             ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 5:
				cout << "   JUNIO            ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 6:
				cout << "   JULIO            ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 7:
				cout << "   AGOSTO           ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 8:
				cout << "   SEPTIEMBRE       ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 9:
				cout << "   OCTUBRE          ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 10:
				cout << "   NOVIEMBRE        ||       $ " << ingresoPorMes[b] << endl;
				break;
			case 11:
				cout << "   DICIEMBRE        ||       $ " << ingresoPorMes[b] << endl;
				break;
			}
		}
	}

	cout << "+------------------------------+" << endl;
	cout << "|   Ingresos anuales: $ " << montoTotal << endl;
	cout << "+------------------------------+" << endl;
}

void ServicioPago::verIngresosMensuales()
{
	system("cls");
	Pago pago;

	int mes, anio;
	float montoTotal = 0, ingresoPorMes[12] = {};

	cout << "   +----------------------------+" << endl;
	cout << "   |      INGRESOS MENSUALES    |" << endl;
	cout << "   +----------------------------+" << endl;
	cout << endl;
	cout << "  Ingrese anio de consulta: ";
	cin >> anio;
	cout << "  Ingrese mes de consulta: ";
	cin >> mes;
	cout << endl;

	int cantPagos = _archivoPago.cantidadRegistros();

	if (cantPagos > 0)
	{
		for (int r = 0; r < cantPagos; r++)
		{
			pago = _archivoPago.leerReg(r);
			if (pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
			{
				montoTotal += pago.getMonto();
			}
		}
	}
	else
	{
		cout << endl;
		cout << "   +-------------------------------------------------+" << endl;
		cout << "   |   No se registragon pagos en el mes ingresado   |" << endl;
		cout << "   +-------------------------------------------------+" << endl;
	}

	cout << "   +-------------------------------------+" << endl;
	cout << "   |      MES      ||      INGRESOS      |" << endl;
	cout << "   +-------------------------------------+" << endl;
	cout << "          " << mes << "       ||      $ " << montoTotal << endl;

}

void ServicioPago::verIngresosAnualesPorSocio()
{
	system("cls");

	ServicioSocio ss;
	Pago pago;
	Socio socio;
	int anio, idSocio, cantMeses = 0; // int contador = 0; para 
	float montoTotal = 0;

	cout << "   +------------------------------------+" << endl;
	cout << "   |      INGRESOS ANUALES POR SOCIO    |" << endl;
	cout << "   +------------------------------------+" << endl;
	cout << endl;
	cout << string(75, '-') << endl;
	cout << "   Ingrese Anio de consulta: ";
	cin >> anio;
	//cout << endl;
	cout << "   Ingrese id del socio: ";
	cin >> idSocio; 
	cout << endl;
	cout << endl;

	int cantPagos = _archivoPago.cantidadRegistros();
	//int cantPagosSocio = _archivoPago.cantidadPagosPorSocio(cantPagos, idSocio);

	if (cantPagos > 0)
	{
		for (int i = 0; i < cantPagos; i++)
		{
			pago = _archivoPago.leerReg(i);
			socio = ss.buscarSocio(idSocio);

			if (pago.getFechaPago().getAnio() == anio && pago.getIdUsuario() == idSocio)
			{
				montoTotal += pago.getMonto();
				cantMeses++;
			}
			//contador++;
		}
		
		cout << "   Socio:  " << socio.getNombre() + " " + socio.getApellido() << endl;
		cout << "   Ingresos totales del anio " << anio << ": " << montoTotal << endl;
		cout << "   Cantidad de meses:  " << cantMeses << endl;
		//cout << " " << left << setw(26) << socio.getNombre() + " " + socio.getApellido() << "| " << right << setw(15) << fixed << setprecision(2) << "$ " << montoTotal << " | " << setw(15) << cantMeses << " |" << endl;
		cout << string(75, '-') << endl;
	}

	/*if (contador == 0)
	{
		system("cls");
		cout << "+-------------------------------------+" << endl;
		cout << "|  No hubo pagos en el anio ingresado |" << endl;
		cout << "+-------------------------------------+" << endl;
		system("pause");
		return;
	}*/
}

int ServicioPago::cantidadDeDiasDelUltimoPago(int idSocio)
{
	Pago pago;
	Fecha fechaActual;

	int cantPagos = _archivoPago.cantidadRegistros();
	int pos = _archivoPago.ultimoPagoSocio(cantPagos, idSocio);

	if (pos == -1)
	{
		pago = _archivoPago.leerReg(pos);

		if (pago.getFechaPago().getAnio() >= fechaActual.getAnio() && pago.getPeriodo().getMes() >= fechaActual.getMes())
		{
			return pago.getFechaPago().getDia() - fechaActual.getDia();
		}
	}
	return -1;
}

void ServicioPago::mostrarListaDePagosPorTipoDePase()
{
		system("cls");
		Pago pago;
		int pase;
		float monto;

		int contador = 0;

		cout << "   +-----------------------------------+" << endl;
		cout << "   |       PAGOS POR TIPO DE PASE      |" << endl;
		cout << "   +-----------------------------------+" << endl;
		cout << endl;
		cout << "  0 - Full | 1 - Smart | 2 - Fit " << endl;
		cout << "  Su seleccion: ";
		cin >> pase;

		switch (pase)
		{
		case 0:
			monto = 55000;
			break;
		case 1:
			monto = 35000;
			break;
		case 2:
			monto = 25000;
			break;
		}

		int cantidad = _archivoPago.cantidadRegistros();

		cout << "+-----------------------------------+" << endl;
		for (int i = 0; i < cantidad; i++)
		{
			pago = _archivoPago.leerReg(i);

			if (pago.getMonto() == monto)
			{
				cout << " Fecha : " << pago.getFechaPago().toString() << endl;
				cout << " ID    : #" << pago.getIdUsuario() << endl;
				cout << " Monto : $" << pago.getMonto() << endl;
				cout << "+-----------------------------------+" << endl;
				contador++;
				if (contador % 10 == 0)
				{
					cout << " Siguiente pagina...." << endl;
					system("pause");
					system("cls");
				}
			}
		}

		if (contador == 0)
		{
			system("cls");
			cout << "+------------------------------------------+" << endl;
			cout << "|  No hay registros para este tipo de pase |" << endl;
			cout << "+------------------------------------------+" << endl;
		}

		system("pause");

}


