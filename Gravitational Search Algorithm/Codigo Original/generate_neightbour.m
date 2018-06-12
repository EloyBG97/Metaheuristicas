function X = generate_neightbour(X)
    dim = size(X);
    position = randi(dim);
    X(position) = X(position) + randn();