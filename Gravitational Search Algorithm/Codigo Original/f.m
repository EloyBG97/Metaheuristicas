function Y = f(F_index, X,dim)
    Y = 0;
    
    if F_index==1
        for i=1:dim
            Y = Y + (10 ^6) ^ ((i - 1)/(dim - 1)) * X(i)^2;
            
        end
    
    end
    
    if F_index==2
        for i=2:dim
        	Y = Y + X(i)^2;
        end
    
        Y = Y * 10^6;
        Y = Y + X(1)^2;
    end
    
    if F_index == 3
        for i=2:dim
            Y = Y + X(i)^2;
        end
        
        Y = Y + 10^6 * X(1) ^ 2;
    end

    if F_index ==  4
        for i=1:dim-1
            Y = Y + 100 * (X(i)^2 + X(i+1))^2 + (X(i) + 1)^2;
        end
    end

    if F_index == 5
        aux1 = 0;
        aux2 = 0;

        for i=1:dim
            aux1 = aux1 + X(i)^2;
            aux2 = aux2 + cos(2 * pi * X(i));
        end
        
        Y = -20 * exp(-0.2 * sqrt(aux1/dim)) -exp(aux2/dim) + 20 + exp(1);      
    end
    
    if F_index==6
        a = 0.5;
        b = 3;
        kmax = 20;
        
        aux1 = 0;
        aux2 = 0;
        
        for i=1:dim
            for j=1:kmax
                aux1 = aux1 + a^j * cos(2*pi*b^j*(X(i)+0.5));
            end
        end
        
        for j=1:kmax
            aux2 = aux2 + a^j * cos(2*pi*b^j*0.5);
        end
       
        Y = aux1 - dim * aux2;
    end
    
    if F_index == 7
        aux1 = 0;
        aux2 = 1;
        
        for i=1:dim
            aux1 = aux1 + (X(i)^2 / 4000);
        end
        
        for i=1:dim
            aux2 = aux2 * cos(X(i)/sqrt(i));
        end
        
        Y = aux1 + aux2 + 1;
    end

    if F_index==8
        Y = 0;
        
        for i=1:dim         
            Y = Y + X(i)^2 - 10*cos(2*pi*X(i)+10);
        end
    end
    
    if F_index == 9
        aux1 = 0;
        
        for i=1:dim
            z = X(i) + 4.209687462275036*exp(2);
            
            if abs(z) <= 500
                aux1 = aux1 + z * sin(sqrt(abs(z)));
            end
            
            if z > 500
                aux1 = aux1 + (500 - mod(z,500))*sin(sqrt(abs(500 - mod(z,500)))) - (z-500)^2/(10000*dim);
            end
            
            if z < - 500
                aux1 = aux1 + (mod(abs(z),500) - 500)*sin(sqrt(abs(mod(z,500)-500))) - (z+500)^2/(10000*dim);
            end
        end
        
        Y = 418.9829*dim + aux1;
    end
    
    if F_index==10
        aux1 = 0;
        aux2=1;
        for i=1:dim
            for j=1:32
                aux1 = aux1 + abs(2^j*X(i) - round(2^j*X(i)))/2^j;
            end
            
            aux2 = aux2 * 1+i*aux1;
            aux1=0;
        end
        
        Y = 10/dim^2 * aux2 - 10/dim^1.2;
    end
                
    if F_index == 11
        aux1 = 0;
        aux2=0;
        aux3=0;
        
        for i=1:dim
            aux1 = aux1 + X(i)^2;
        end
        
        aux1 = abs(aux1 - dim)^(1/4);
        
        for i=1:dim
            aux2 = aux2 + X(i)^2;
            aux3 = aux3 + X(i);
        end
        
        Y = aux1 + (0.5*aux2 + aux3)/dim + 0.5;
    end
    
    if F_index == 12
        aux1 = 0;
        aux2=0;
        aux3=0;
        aux4 = 0;
        
        for i=1:dim
            aux1 = aux1 + X(i)^2;
        end
        
        aux1 = aux1^2;
        
        for i=1:dim
            aux4 = aux4 + X(i);
        end
        
        aux4 = aux4^2;
        
        for i=1:dim
            aux2 = aux2 + X(i)^2;
            aux3 = aux3 + X(i);
        end
        
        Y = abs(aux1 - aux4)^0.5 + (0.5*aux2 + aux3)/dim + 0.5;
    end
    
    if F_index==13
        Y = 0;
        for i=1:dim-1
            Y = Y + f(7,f(4,X(i:i+1),2),1);
        end
        
        Y = Y + f(7,f(4,[X(dim), X(1)],2),1);
    end
    
    if F_index==14
        Y = 0;
        
        for i=1:dim-1
            Y = Y + 0.5 + (sin(sqrt(X(i)^2 + X(i+1)^2)-0.5)^2)/(1 + 0.001*(X(i)^2 + X(i+1)^2))^2;
        end
        
                    Y = Y + 0.5 + (sin(sqrt(X(dim)^2 + X(1)^2)-0.5)^2)/(1 + 0.001*(X(dim)^2 + X(1)^2))^2;
    end
    