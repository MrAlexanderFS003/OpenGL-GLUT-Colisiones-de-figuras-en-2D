class Circulo {
	float posXC = 0.0f, posYC = 0.0f;
	float posX = 10.0f, posY = 10.0f;
	int radio = 5;
	bool pinta;
public:
	Circulo(){}
	void Dibuja();
	void RellenoCirculo();
	void Actualiza();

	// Setters y Getters
	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosX() { return posX; }
	float getPosY() { return posY; }

	void setPinta(bool valor) { pinta = valor; }
};