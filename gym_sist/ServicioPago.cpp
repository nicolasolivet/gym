#include <iostream>
#include "Pago.h"
#include "ServicioPago.h"
#include "ArchivoPagos.h"
#include "ServicioPago.h"
#include "ServicioSocio.h"

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

void ServicioPago::verPago(int idSocio)
{
	system("cls");

	Pago pago;
	int* pagosSocio;

	int cantPagos = _archivoPago.cantidadRegistros();
	int cantPagosSocio = _archivoPago.cantidadPagosPorSocio(cantPagos, idSocio);

	if (cantPagosSocio > 0)
	{
		pagosSocio = new int[cantPagosSocio];
		if (pagosSocio == nullptr) { return; }

		*pagosSocio = _archivoPago.leerPagosPorSocio(cantPagos, pagosSocio, idSocio);
		for (int i = 0; i < cantPagosSocio; i++)
		{
			pago = _archivoPago.leerReg(pagosSocio[i]);
		}

		cout << "+--------------------------+" << endl;
		cout << "| ID #" << pago.getIdUsuario() << "                 |" << endl;
		cout << "| Fecha de pago: " << pago.getFechaPago().toString() << " |" << endl;
		cout << "| Monto: $" << pago.getMonto() << "            |" << endl;
		cout << "+--------------------------+" << endl;
	}
	else
	{
		cout << "+-----------------------------+" << endl;
		cout << "|   No se registraron pagos   |" << endl;
		cout << "+-----------------------------+" << endl;
	}

	delete[]pagosSocio;
	system("pause");

	// traer cantidades
	// asignar memoria dinamica a el vector
	// llenar el vector
	// ciclar el vector para leerlo 
	// mostrar info
}

//void ServicioPago::listarTotalPagos()
//{
//
//    system("cls");
//    Pago* vPagos;
//
//    int cantPagos = _archivoPago.getCantidadPagos();
//    vPagos = new Pago[cantPagos];
//    if(vPagos == nullptr)
//    {
//        return;
//    }
//
//    if (cantPagos > 0)
//    {
//        for (int i = 0; i < cantPagos; i++)
//        {
//            _archivoPago.leerTodosPagos(vPagos, cantPagos);
//
//            cout << "+--------------------------+" << endl;
//            cout << "| ID #" << vPagos[i].getIdUsuario() << "           |" << endl;
//            cout << "| Fecha de pago: " << vPagos[i].getFechaPago().toString() << " |" << endl;
//            cout << "| Monto: $" << vPagos[i].getMonto() << "     |" << endl;
//            cout << "+--------------------------+" << endl;
//        }
//    }
//    else
//    {
//        cout << "+-------------------------+" << endl;
//        cout << "|  No se registran pagos  |" << endl;
//        cout << "+-------------------------+" << endl;
//    }
//
//    delete []vPagos;
//
//    system("pause");
//}
//
//void ServicioPago::verPagosPorMes()
//{
//    system("cls");
//    Pago pago;
//    int mes, anio;
//
//    int contador = 0;
//
//    cout << "+-----------------------------------+" << endl;
//    cout << "|            LISTA POR MES          |" << endl;
//    cout << "+-----------------------------------+" << endl;
//    cout << endl;
//    cout << " Ingrese Anio: ";
//    cin >> anio;
//    cout << " Ingrese mes: ";
//    cin >> mes;
//
//    int cantidad = _archivoPago.getCantidadPagos();
//
//    cout << "+-----------------------------------+" << endl;
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//
//        if (pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
//        {
//            cout << " Fecha : " << pago.getFechaPago().toString() << endl;
//            cout << " ID    : #" << pago.getIdUsuario() << endl;
//            cout << " Monto : $" << pago.getMonto() << endl;
//            cout << "+-----------------------------------+" << endl;
//            contador++;
//            if(contador%10 == 0)
//            {
//                cout << " Siguiente pagina...." << endl;
//                system("pause");
//                system("cls");
//
//                contador=0;
//            }
//        }
//    }
//
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+------------------------------------+" << endl;
//        cout << "|  No hubo pagos en el mes ingresado |" << endl;
//        cout << "+------------------------------------+" << endl;
//    }
//
//    system("pause");
//}
//
//void ServicioPago::verPagosPorAnio()
//{
//    system("cls");
//    Pago pago;
//    int anio;
//
//    int contador = 0;
//
//    cout << "+-----------------------------------+" << endl;
//    cout << "|           LISTA POR ANIO          |" << endl;
//    cout << "+-----------------------------------+" << endl;
//    cout << endl;
//    cout << " Ingrese Anio: ";
//    cin >> anio;
//
//    int cantidad = _archivoPago.getCantidadPagos();
//
//    cout << "+-----------------------------------+" << endl;
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//
//        if (pago.getFechaPago().getAnio() == anio )
//        {
//            cout << " Fecha : " << pago.getFechaPago().toString() << endl;
//            cout << " ID    : #" << pago.getIdUsuario() << endl;
//            cout << " Monto : $" << pago.getMonto() << endl;
//            cout << "+-----------------------------------+" << endl;
//            contador++;
//            if(contador%10 == 0)
//            {
//                cout << " Siguiente pagina...." << endl;
//                system("pause");
//                system("cls");
//
//                contador=0;
//            }
//        }
//    }
//
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+-------------------------------------+" << endl;
//        cout << "|  No hubo pagos en el anio ingresado |" << endl;
//        cout << "+-------------------------------------+" << endl;
//    }
//
//    system("pause");
//}
//
//void ServicioPago::verIngresosAnuales()
//{
//
//    system("cls");
//    Pago pago;
//
//    float vectorMeses[12] {};
//    float total = 0;
//
//    int anio;
//
//    int contador = 0;
//
//    cout << "+-------------------------------------+" << endl;
//    cout << "|         ESTADISTICAS ANUALES        |" << endl;
//    cout << "+-------------------------------------+" << endl;
//    cout << endl;
//    cout << " Ingrese Anio de consulta: ";
//    cin >> anio;
//
//    int cantidad = _archivoPago.getCantidadPagos();
//
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//
//        if (pago.getFechaPago().getAnio() == anio)
//        {
//            vectorMeses[pago.getFechaPago().getMes() - 1] += pago.getMonto();
//            total += pago.getMonto();
//            contador++;
//        }
//    }
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+-------------------------------------+" << endl;
//        cout << "|  No hubo pagos en el anio ingresado |" << endl;
//        cout << "+-------------------------------------+" << endl;
//        system("pause");
//        return;
//    }
//
//    cout << "------------------------------------" << endl;
//    cout << " MES             ||       INGRESOS" << endl;
//    cout << "------------------------------------" << endl;
//    for (int i = 0; i < 12; i++)
//    {
//        if (vectorMeses[i] != 0)
//        {
//            switch (i)
//            {
//            case 0:
//                cout << " ENERO           ||   $" << vectorMeses[i] << endl;
//                break;
//            case 1:
//                cout << " FEBRERO         ||   $" << vectorMeses[i] << endl;
//                break;
//            case 2:
//                cout << " MARZO           ||   $" << vectorMeses[i] << endl;
//                break;
//            case 3:
//                cout << " ABRIL           ||   $" << vectorMeses[i] << endl;
//                break;
//            case 4:
//                cout << " MAYO            ||   $" << vectorMeses[i] << endl;
//                break;
//            case 5:
//                cout << " JUNIO           ||   $" << vectorMeses[i] << endl;
//                break;
//            case 6:
//                cout << " JULIO           ||   $" << vectorMeses[i] << endl;
//                break;
//            case 7:
//                cout << " AGOSTO          ||   $" << vectorMeses[i] << endl;
//                break;
//            case 8:
//                cout << " SEPTIEMBRE      ||   $" << vectorMeses[i] << endl;
//                break;
//            case 9:
//                cout << " OCTUBRE         ||   $" << vectorMeses[i] << endl;
//                break;
//            case 10:
//                cout << " NOVIEMBRE       ||   $" << vectorMeses[i] << endl;
//                break;
//            case 11:
//                cout << " DICIEMBRE       ||   $" << vectorMeses[i] << endl;
//                break;
//            }
//        }
//
//    }
//    cout << "------------------------------------" << endl;
//    cout << " TOTAL ACUMULADO: " << total << endl;
//    cout << "------------------------------------" << endl;
//
//    system("pause");
//}
//
//void ServicioPago::verIngresosMensuales()
//{
//
//    system("cls");
//    Pago pago;
//    int mes, anio;
//
//    float montoTotal = 0;
//
//    int contador = 0;
//
//    cout << "+------------------------------------------+" << endl;
//    cout << "|           ESTADISTICAS MENSUALES         |" << endl;
//    cout << "+------------------------------------------+" << endl;
//    cout << endl;
//    cout << " Ingrese Anio: ";
//    cin >> anio;
//    cout << " Ingrese mes: ";
//    cin >> mes;
//
//    int cantidad = _archivoPago.CantidadPagos();
//
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//
//        if (pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
//        {
//            montoTotal += pago.getMonto();
//            contador++;
//        }
//    }
//
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+--------------------------------------+" << endl;
//        cout << "|  No hubo pagos en la fecha ingresada |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        system("pause");
//        return;
//    }
//
//    cout << endl;
//    cout << "+------------------------------------------+" << endl;
//    cout << " MES: " << mes << " || INGRESOS: $" << montoTotal << endl;
//    cout << "+------------------------------------------+" << endl;
//
//    system("pause");
//}
//
//int ServicioPago::cantidadDeDiasDelUltimoPago(int idSocio)
//{
//
//    Pago pago;
//    Fecha fechaActual;
//
//    int cantPagos = _archivoPago.getCantidadPagos();
//    int pos = _archivoPago.ultimoPagoSocio(cantPagos, idSocio);
//
//    if (pos != -1)
//    {
//        pago = _archivoPago.leerPago(pos);
//
//        if (pago.getPeriodo().getAnio() >= fechaActual.getAnio() && pago.getPeriodo().getMes() >= fechaActual.getMes())
//        {
//            return pago.getPeriodo().getDia() - fechaActual.getDia();
//        }
//
//    }
//
//    return -1;
//
//}
//
//void ServicioPago::mostrarListaDePagosPorTipoDePase()
//{
//    system("cls");
//    Pago pago;
//    int pase;
//    float monto;
//
//    int contador = 0;
//
//    cout << "+-----------------------------------+" << endl;
//    cout << "|       LISTA POR TIPO DE PASE      |" << endl;
//    cout << "+-----------------------------------+" << endl;
//    cout << endl;
//    cout << " 0 - Full | 1 - Smart | 2 - Fit " << endl;
//    cout << " Su seleccion: ";
//    cin >> pase;
//
//    switch (pase)
//    {
//    case 0:
//        monto = 55000;
//        break;
//    case 1:
//        monto = 35000;
//        break;
//    case 2:
//        monto = 25000;
//        break;
//    }
//
//    int cantidad = _archivoPago.getCantidadPagos();
//
//    cout << "+-----------------------------------+" << endl;
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//
//        if (pago.getMonto() == monto )
//        {
//            cout << " Fecha : " << pago.getFechaPago().toString() << endl;
//            cout << " ID    : #" << pago.getIdUsuario() << endl;
//            cout << " Monto : $" << pago.getMonto() << endl;
//            cout << "+-----------------------------------+" << endl;
//            contador++;
//            if(contador%10 == 0)
//            {
//                cout << " Siguiente pagina...." << endl;
//                system("pause");
//                system("cls");
//            }
//        }
//    }
//
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+------------------------------------------+" << endl;
//        cout << "|  No hay registros para este tipo de pase |" << endl;
//        cout << "+------------------------------------------+" << endl;
//    }
//
//    system("pause");
//}

//void ServicioPago::verIngresosAnualesPorSocios()
//{
//    system("cls");
//
//    Pago pago, pagoAux;
//    ServicioSocio sSocio;
//    Socio socio;
//
//    float total = 0;
//
//    int anio, cantMeses = 0;
//
//    int contador = 0;
//
//    cout << "------------------------------------" << endl;
//    cout << " Ingrese Anio de consulta: ";
//    cin >> anio;
//
//    system("cls");
//    int cantidad = _archivoPago.getCantidadPagos();
//
//    cout << " INFORME DE INGRESOS ANUALES POR SOCIOS: " << anio << endl;
//    cout << "+-------------------------------------------------------------------------+" << endl;
//    cout << " SOCIO                     | RECAUDACION              | MESES INSCRIPTOS" << endl;
//    cout << "+-------------------------------------------------------------------------+" << endl;
//
//    for (int i = 0; i < cantidad; i++)
//    {
//        pago = _archivoPago.leerPago(i);
//        socio = sSocio.buscarSocioId(pago.getIdUsuario());
//
//        if (pago.getFechaPago().getAnio() == anio)
//        {
//
//            for (int j = 0; j < cantidad; j++)
//            {
//                pagoAux = _archivoPago.leerPago(j);
//                if(pagoAux.getIdUsuario() == socio.getIdUsuario())
//                {
//                    total += pagoAux.getMonto();
//                    cantMeses++;
//                }
//            }
//        }
//
//        cout << " " << left << setw(26) << socio.getNombre() + " " + socio.getApellido() << "| " << right << setw(15) << fixed << setprecision(2) << "$ " << total << " | " << setw(15) << cantMeses << " |" << endl;
//
//        total = 0;
//        cantMeses = 0;
//
//        contador++;
//
//    }
//    cout << "+-------------------------------------------------------------------------+" << endl;
//
//    if (contador == 0)
//    {
//        system("cls");
//        cout << "+-------------------------------------+" << endl;
//        cout << "|  No hubo pagos en el anio ingresado |" << endl;
//        cout << "+-------------------------------------+" << endl;
//        system("pause");
//        return;
//    }
//
//    cout << endl;
//    system("pause");
//}
