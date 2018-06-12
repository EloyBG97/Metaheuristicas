function [X, fitness] = improvekMass(X, fitness, F_index, min_flag)

    kbest = 1;
    
    [Ms, ds] = sort(fitness, 'descend');
    
    for i=1:kbest;
        j = ds(i);
        X(j) = local_search(X(j), F_index, min_flag);
    end
    fitness = evaluateF(X, F_index);
    
end