class Accesoire: public Decorator
{
private:

public:
    virtual double getVitesse() const override;
    virtual double getCamouflage() const override;
    virtual void toString() override;
    

}