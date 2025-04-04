#include <iostream>
#include "Banco.h"
#include "CuentaAhorro.h"
#include "CuentaCorriente.h"
#include "CuentaPlazoFijo.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=========== MENU PRINCIPAL ===========" << endl;
    cout << "1. Registrar nuevo cliente" << endl;
    cout << "2. Buscar cuentas por CI" << endl;
    cout << "3. Realizar deposito" << endl;
    cout << "4. Realizar retiro" << endl;
    cout << "5. Consultar historial de una cuenta" << endl;
    cout << "6. Crear nueva cuenta para cliente" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void registrarCliente(Banco& banco) {
    int ci;
    string nombre, apellido;

    cout << "Ingrese CI: ";
    cin >> ci;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;

    banco.agregarCliente(ci, nombre, apellido);
    cout << "Cliente registrado exitosamente." << endl;
}

void buscarCuentasPorCI(Banco& banco) {
    int ci;
    cout << "Ingrese el CI del cliente: ";
    cin >> ci;

    Cliente* cliente = banco.buscarCliente(ci);
    if (cliente != nullptr) {
        cout << "\n=== Cuentas del cliente " << cliente->getNombre() << " " << cliente->getApellido() << " ===\n";
        cliente->mostrarCuentas();
    }
    else {
        cout << "Cliente no encontrado.\n";
    }
}


void realizarDeposito(Banco& banco) {
    int ci;
    cout << "Ingrese el CI del cliente: ";
    cin >> ci;

    Cliente* cliente = banco.buscarCliente(ci);
    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    ModuloCuenta& modulo = cliente->getModuloCuenta();

    if (modulo.getIndice() == 0) {
        cout << "Este cliente no tiene cuentas registradas.\n";
        return;
    }

    // Mostrar cuentas sin usar getCuenta(i)
    cout << "\nCuentas del cliente " << cliente->getNombre() << " " << cliente->getApellido() << ":\n";

    // Mostrar usando el arreglo interno directamente
    for (int i = 0; i < modulo.getIndice(); i++) {
        Cuenta* cuenta = modulo.buscarPorPosicion(i); // ← la creamos abajo
        if (cuenta != nullptr) {
            cout << "- Nro Cuenta: " << cuenta->getNroCuenta()
                << " | Saldo: " << cuenta->getSaldo() << endl;
        }
    }

    // Elegir la cuenta
    int nroSeleccionado;
    cout << "Ingrese el numero de cuenta a la que desea depositar: ";
    cin >> nroSeleccionado;

    Cuenta* cuentaSeleccionada = modulo.buscar(nroSeleccionado);
    if (!cuentaSeleccionada) {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    float monto;
    cout << "Ingrese el monto a depositar: ";
    cin >> monto;

    if (monto <= 0) {
        cout << "El monto debe ser mayor que cero.\n";
        return;
    }

    Fecha fechaActual = Fecha::hoy();
    cuentaSeleccionada->depositar(monto, fechaActual);

    cout << "Deposito realizado exitosamente.\n";
}


void realizarRetiro(Banco& banco) {
    int ci;
    cout << "Ingrese el CI del cliente: ";
    cin >> ci;

    Cliente* cliente = banco.buscarCliente(ci);
    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    ModuloCuenta& modulo = cliente->getModuloCuenta();

    if (modulo.getIndice() == 0) {
        cout << "Este cliente no tiene cuentas registradas.\n";
        return;
    }

    // Mostrar cuentas del cliente
    cout << "\nCuentas del cliente " << cliente->getNombre() << " " << cliente->getApellido() << ":\n";
    for (int i = 0; i < modulo.getIndice(); i++) {
        Cuenta* cuenta = modulo.buscarPorPosicion(i);
        if (cuenta != nullptr) {
            cout << "- Nro Cuenta: " << cuenta->getNroCuenta()
                << " | Saldo: " << cuenta->getSaldo() << endl;
        }
    }

    int nroSeleccionado;
    cout << "Ingrese el numero de cuenta desde la cual desea retirar: ";
    cin >> nroSeleccionado;

    Cuenta* cuentaSeleccionada = modulo.buscar(nroSeleccionado);
    if (!cuentaSeleccionada) {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    float monto;
    cout << "Ingrese el monto a retirar: ";
    cin >> monto;

    if (monto <= 0) {
        cout << "El monto debe ser mayor que cero.\n";
        return;
    }

    Fecha fechaActual = Fecha::hoy();

    if (cuentaSeleccionada->retirar(monto, fechaActual)) {
        cout << "Retiro realizado exitosamente.\n";
    }
    else {
        cout << "No se pudo realizar el retiro.\n";
    }
}




void consultarHistorial(Banco& banco) {
    int ci;
    cout << "Ingrese el CI del cliente: ";
    cin >> ci;

    Cliente* cliente = banco.buscarCliente(ci);
    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    ModuloCuenta& modulo = cliente->getModuloCuenta();

    if (modulo.getIndice() == 0) {
        cout << "Este cliente no tiene cuentas registradas.\n";
        return;
    }

    // Mostrar cuentas
    cout << "\nCuentas del cliente " << cliente->getNombre() << " " << cliente->getApellido() << ":\n";
    for (int i = 0; i < modulo.getIndice(); i++) {
        Cuenta* cuenta = modulo.buscarPorPosicion(i);
        if (cuenta != nullptr) {
            cout << "- Nro Cuenta: " << cuenta->getNroCuenta()
                << " | Saldo: " << cuenta->getSaldo() << endl;
        }
    }

    int nroSeleccionado;
    cout << "Ingrese el numero de cuenta para ver su historial: ";
    cin >> nroSeleccionado;

    Cuenta* cuenta = modulo.buscar(nroSeleccionado);
    if (!cuenta) {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    cout << "\n=== Historial de operaciones ===\n";
    cuenta->mostrarHistorial(); // ✅ método que ya deberías tener en Cuenta
}


void crearCuentaParaCliente(Banco& banco) {
    int ci;
    cout << "Ingrese el CI del cliente: ";
    cin >> ci;

    Cliente* cliente = banco.buscarCliente(ci);
    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    cout << "\nSeleccione el tipo de cuenta a crear:\n";
    cout << "1. Cuenta de Ahorro\n";
    cout << "2. Cuenta Corriente\n";
    cout << "3. Cuenta a Plazo Fijo\n";
    cout << "Opcion: ";
    int tipo;
    cin >> tipo;

    if (tipo < 1 || tipo > 3) {
        cout << "Opcion invalida.\n";
        return;
    }

    int nroCuenta;
    float saldo;
    cout << "Ingrese el numero de la cuenta: ";
    cin >> nroCuenta;

    // Verificar que la cuenta no exista ya
    if (cliente->getModuloCuenta().buscar(nroCuenta)) {
        cout << "Ya existe una cuenta con ese numero.\n";
        return;
    }

    cout << "Ingrese el saldo inicial: ";
    cin >> saldo;

    Fecha fechaActual = Fecha::hoy();
    Cuenta* nuevaCuenta = nullptr;

    if (tipo == 1) {
        nuevaCuenta = new CuentaAhorro(nroCuenta, saldo, cliente, fechaActual);
    }
    else if (tipo == 2) {
        nuevaCuenta = new CuentaCorriente(nroCuenta, saldo, cliente, fechaActual);
    }
    else if (tipo == 3) {
        int dia, mes, anio;
        cout << "Ingrese la fecha de vencimiento (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        Fecha fechaVencimiento(dia, mes, anio);
        nuevaCuenta = new CuentaPlazoFijo(nroCuenta, saldo, cliente, fechaActual, fechaVencimiento);
    }

    cliente->agregarCuenta(nuevaCuenta);
    cout << "Cuenta creada exitosamente.\n";
}




int main() {
    Banco banco("pepe");
    int opcion;

    do {
        mostrarMenu();      // <- llamado aquí
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrarCliente(banco);
            break;
        case 2:
            buscarCuentasPorCI(banco);
            break;
        case 3:
            realizarDeposito(banco);
            break;
        case 4:
            realizarRetiro(banco); 
            break;
        case 5:
            consultarHistorial(banco);
            break;
        case 6:
            crearCuentaParaCliente(banco);
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
      

    } while (opcion != 0);

    return 0;
}