function M = readRotationMatrix(F_index, dim)
    dir = '/media/eloy/Datos/UGR/3º Carrera/2ºCuatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/M/';
    file = strcat(dir, 'M_', int2str(F_index), '_D', int2str(dim),'.txt');
    
    M = dlmread(file);
