import threading

semaforo = threading.Semaphore(1)
contador = 0

def funcion_hilo():
    global contador
    for i in range(1000000):
        semaforo.acquire() # Esperar a que el semáforo esté libre
        contador += 1 # Acceder al recurso compartido
        semaforo.release() # Liberar el semáforo

# Crear los hilos
hilo1 = threading.Thread(target=funcion_hilo)
hilo2 = threading.Thread(target=funcion_hilo)

# Iniciar los hilos
hilo1.start()
hilo2.start()

# Esperar a que los hilos terminen
hilo1.join()
hilo2.join()

print("El valor del contador es", contador)