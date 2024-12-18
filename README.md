# Minishell

El proyecto **Minishell** forma parte del currículo de 42 y consiste en la implementación de una shell mínima que emula las funcionalidades básicas de bash. Este proyecto está diseñado para desarrollar habilidades en manejo de procesos, señales y parsers, además de profundizar en el funcionamiento interno de un intérprete de comandos.

---

## 🚀 Descripción del Proyecto

Minishell permite ejecutar comandos básicos de una shell, gestionar pipes, redirecciones y variables de entorno. Este proyecto es una introducción práctica a los sistemas operativos y su interacción con el terminal.

---

## 🔧 Requisitos

### Funcionalidades Principales
- Ejecución de comandos simples.
- Pipes (`|`) para conectar la salida de un comando con la entrada de otro.
- Redirecciones (`<`, `>`, `>>`) para manejar archivos.
- Variables de entorno.
- Gestión de señales como `Ctrl+C`, `Ctrl+D`, y `Ctrl+\`.
- Comandos integrados (*built-ins*):
  - `echo` con la opción `-n`.
  - `cd`.
  - `pwd`.
  - `export`.
  - `unset`.
  - `env`.
  - `exit`.

### Restricciones
- No se permite el uso de funciones prohibidas (como `system`, entre otras).
- El proyecto debe manejar errores y comportarse de manera robusta ante entradas incorrectas.

---

## 📁 Estructura del Proyecto

```plaintext
minishell/
├── srcs/           # Código fuente principal
├── includes/       # Archivos de cabecera
├── libft/          # Librería personalizada
├── Makefile        # Sistema de compilación
└── README.md       # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/minishell.git
   cd minishell
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta Minishell:
   ```bash
   ./minishell
   ```

4. Usa la shell como lo harías con bash:
   ```bash
   echo "Hola, mundo!"
   ls -l | grep minishell
   ```

---

## 🌟 Características

- Manejo de múltiples procesos mediante `fork` y `execve`.
- Gestión de errores y señales para una experiencia de usuario fluida.
- Simplicidad en el diseño del parser para comandos y argumentos.
- Comportamiento similar a bash para facilitar su uso.

---

## 🧪 Testing

Prueba la ejecución de varios comandos y combinaciones:

```bash
ls -l | grep minishell > output.txt
cat < input.txt | sort | uniq > result.txt
export VAR=test && echo $VAR
```

Comprueba el comportamiento con entradas incorrectas para validar su robustez:

```bash
ls || echo "Esto no debería ejecutarse"
cat inexistente.txt
```

---
