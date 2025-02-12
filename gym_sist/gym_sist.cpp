#include <iostream>
#include <iomanip>
#include "ServicioSocio.h"
#include "ServicioPago.h"
#include "ServicioReclamo.h"
#include "ArchivoPagos.h"
using namespace std;

bool haylugar()
{
	return 22 < 25;
}

int main()
{

	//cout << string(105, '-') << endl;
	//cout << left << setw(5) << "ID" << "|"
	//	<< setw(13) << "Apellido" << "|"
	//	<< setw(12) << "Nombre" << "|"
	//	<< setw(14) << "Fecha Ing." << "|"
	//	<< setw(45) << "Membresia" << "|"
	//	<< setw(20) << "Estado" << endl;
	//cout << string(105, '-') << endl;

	//cout << " " << left << setw(26) << socio.getNombre() + " " + socio.getApellido() << "| " << right << setw(15) << fixed << setprecision(2) << "$ " << montoTotal << " | " << setw(15) << cantMeses << " |" << endl;

	//cout << " " << left << setw(26) << "Nicolas Olivet " << "| " /* << right*/ << setw(15) << fixed << setprecision(2) << "$ " << 10.000 << " | " << setw(15) << 12 << " |" << endl;

	//cout << string(105, '-') << endl;
	//cout << left << setw(5) << "ID" << "|"
	//	<< setw(13) << "Apellido" << "|"
	//	<< setw(12) << "Nombre" << "|"
	//	<< setw(14) << "Fecha Ing." << "|"
	//	<< setw(45) << "Pase" << "|"
	//	<< setw(20) << "Estado" << endl;
	//cout << string(105, '-') << endl;

	cout << string(65, '-') << endl;
	cout << left << setw(25) << "| ENTRENADOR" << "|"
		<< setw(25) << " HORARIO" << endl;
	cout << string(65, '-') << endl;
	cout << left << setw(25) << "| nicolas olivet" << "|"
		<< setw(25) << "08hs a 13hs" << endl;
	cout << string(65, '-') << endl;

	//cout << string(30, '|-') << endl;
	//cout << "| Fecha \t|Socio ID \t" << endl;
	//cout << string(30, '-') << endl;

	//cout << left << setw(19) << " Nombre: " << "Pepe" << endl;
	//cout << setw(19) << " Apellido: "<< endl;
	//cout << setw(19) << " Fecha de ingreso: " << endl;
	//cout << setw(19) << " Legajo: " << endl;


	//cout << " + -------------------------------------------------------- +" << endl;
	//cout << " | 1 - Modifisdfsdfds                                       |" << endl;
	//cout << " + -------------------------------------------------------- +" << endl;
	//cout << " | 2 - Modificar Fecha de Nacimiento -                      |" << endl;
	//cout << " + -------------------------------------------------------- +" << endl;
	//cout << " | 3 - Modificar Estado / Eliminar  asdkljaskldjalkjdklsad  |" << endl;
	//cout << " + -------------------------------------------------------- +" << endl;
	return 0;
}