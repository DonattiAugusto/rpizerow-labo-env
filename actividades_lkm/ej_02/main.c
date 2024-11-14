#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>

// Variables globales para los hilos de kernel
static struct task_struct *kthread_1 = NULL;
static struct task_struct *kthread_2 = NULL;

// Función para el primer hilo
static int thread_fn1(void *data) {
    while (!kthread_should_stop()) {
        pr_info("doantti_augusto_ej02: Hola desde el primer hilo!\n");
        ssleep(1); // Pausa de 1 segundo antes de volver a ejecutar
    }
    return 0;
}

// Función para el segundo hilo
static int thread_fn2(void *data) {
    while (!kthread_should_stop()) {
        pr_info("doantti_augusto_ej02: Hola desde el segundo hilo!\n");
        ssleep(1); // Pausa de 1 segundo antes de volver a ejecutar
    }
    return 0;
}

/**
 * @brief Se llama cuando se carga en el kernel
*/
static int __init ej02_module_init(void) {
    // Creación del primer hilo
    kthread_1 = kthread_create(thread_fn1, NULL, "kthread_1");
    if (IS_ERR(kthread_1)) {
        pr_err("doantti_augusto_ej02: Error al crear el primer hilo.\n");
        return PTR_ERR(kthread_1);
    }

    // Creación del segundo hilo
    kthread_2 = kthread_create(thread_fn2, NULL, "kthread_2");
    if (IS_ERR(kthread_2)) {
        pr_err("doantti_augusto_ej02: Error al crear el segundo hilo.\n");
        kthread_stop(kthread_1); // Detener primer hilo en caso de error
        return PTR_ERR(kthread_2);
    }

    // Iniciar los hilos
    wake_up_process(kthread_1);
    wake_up_process(kthread_2);

    pr_info("doantti_augusto_ej02: Módulo cargado y hilos iniciados.\n");
    return 0;
}

/**
 * @brief Se llama cuando se retira del kernel
*/
static void __exit ej02_module_exit(void) {
    // Detener los hilos de manera segura
    if (kthread_1) {
        kthread_stop(kthread_1);
        pr_info("doantti_augusto_ej02: Primer hilo detenido.\n");
    }
    if (kthread_2) {
        kthread_stop(kthread_2);
        pr_info("doantti_augusto_ej02: Segundo hilo detenido.\n");
    }

    pr_info("doantti_augusto_ej02: Módulo descargado.\n");
}

// Registro de las funciones de inicialización y salida
module_init(ej02_module_init);
module_exit(ej02_module_exit);

// Información del módulo
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Augusto Doantti");
MODULE_DESCRIPTION("Módulo del kernel con dos hilos que imprimen mensajes alternados");
