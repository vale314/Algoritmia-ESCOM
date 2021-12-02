var subsets = function (nums) {
  //Guardo los valores
  var array = [];

  //function buscar
  var buscar = (index, current = []) => {
    array.push([...current]);
    // guardamos todos los actuales o el current pero con spread XD

    //para cada elemento donde vamos iteramos en la entrada
    for (let i = index; i < nums.length; i++) {
      //para cada elemento agregamos a current push
      current.push(nums[i]);

      // mandamos nuestra funcion con el valor actual y avanzamos uno en entrada
      buscar(i + 1, current);

      // popeamos un elemento, (el ultimo para hacer las combinaciones del actual)
      current.pop();
    }
  };

  //llamamos a buscar para i, 0 el entrada es global
  buscar(0);

  //regresamos nuestro arreglo
  return array;
};
