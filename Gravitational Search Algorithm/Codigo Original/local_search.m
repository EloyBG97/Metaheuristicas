%%
% 
% 

function X = local_search(X,F_index, min_flag)
    [N, dim] = size(X);
    
    fitness = evaluateF(X, F_index);
    max_neightbour = 20 * dim;
    
    
    for i=1:N
       
        if min_flag == 1    %minimize problem
            
            FNbest = -Inf;
            while(FNbest < fitness(i))
                FNbest = fitness(i);
                Nbest = X(i,:);

                for j=1:max_neightbour
                    neightbour = generate_neightbour(X(i,:));
                    Fneightbour = evaluateF(neightbour, F_index);

                    if(Fneightbour < FNbest)
                        FNbest = Fneightbour;
                        Nbest = neightbour;                   
                    end
                end
                
                if(FNbest < fitness(i))
                        fitness(i) = FNbest;
                        X(i,:) = Nbest;
                end
            end
            
        else                %maximize problem
            FNbest = Inf;
        
            while(FNbest > fitness(i))
                FNbest = fitness(i);
                Nbest = X(i,:);

                for j=1:max_neightbour
                    neightbour = generate_neightbour(X(i,:));
                    Fneightbour = evaluateF(neightbour, F_index);

                    if(Fneightbour > FNbest)
                        FNbest = Fneightbour;
                        Nbest = neightbour;                   
                    end
                end
                
                if(FNbest > fitness(i))
                        fitness(i) = FNbest;
                        X(i,:) = Nbest;
                end
            end
        end
        
    end
        
end
