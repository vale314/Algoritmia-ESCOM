var number = (arrayN, num) => {
  n = arrayN.shift(); //Eliminar El Primero

  array10 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]; // Todos los botones

  arrayC = []; // Botones Inicializacion

  arrayC = array10.filter((x) => !arrayN.includes(x)); // Los botones que si funcionan

  var i = num + ""; // El numero a buscar lo hacemos String

  i = i.length; // Obtener el num de digitos del numero a buscar

  // Iterar i-1 veces las combinaciones posibles con los numeros
  while (i > 1) {
    arrayC = arrayC.flatMap((d) => arrayC.map((v) => d + "" + v));
    i--;
  }

  // Buscar El numero mas cercano al buscado
  var closest = arrayC.reduce(function (prev, curr) {
    return Math.abs(curr - num) < Math.abs(prev - num) ? curr : prev;
  });

  console.log(Math.abs(num - closest));
};

// ( [Numero Entradas, x1,x2, ..., xn], numero a buscar)
number([3, 0, 8, 9], 35);
