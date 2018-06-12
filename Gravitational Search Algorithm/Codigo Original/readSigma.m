function M = readSigma(F_index, dim)
    numberdir = '/media/eloy/Datos/UGR/3º Carrera/2ºCuatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/sigma/Real Distribution/';
    positiondir = '/media/eloy/Datos/UGR/3º Carrera/2ºCuatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/sigma/';

    positionfile = strcat(positiondir, 'shuffle_data_', int2str(F_index), '_D', int2str(dim),'.txt');
    numberfile = strcat(numberdir, 'shift_data_', int2str(F_index), '.txt');

    mreal = dlmread(numberfile);
    mpos = dlmread(positionfile);


for i=1:dim
    M(i) = mreal(1, mpos(i));
end