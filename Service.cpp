#include "Service.h"
#include "RepoCSV.h"

Service::Service()
{
	this->repo = new Repo();
}

Service::Service(const Service& s)
{
	this->repo = s.repo;
}

void Service::setRepo(string optiune_1,string filename_1,string filename_2)
{
	if (optiune_1 == "CSV")
		this->repo = new RepoCSV(filename_1);
	else
		this->repo= new RepoTXT(filename_2);
}

void Service::addMateriale(string nume, string data, int valoare, int durataDeViata, int numarDeExemplare)
{
	Resursa* mat = new Materiale(nume,data,valoare,durataDeViata,  numarDeExemplare);
	this->repo->addElem(*mat);

}

void Service::addFinanciare(string nume, string data, int valoare, string moneda)
{
	Resursa* mat = new Financiare(nume, data, valoare, moneda);
	this->repo->addElem(*mat);

}

void Service::updateResursa(Resursa& f1, Resursa& f2)
{
	this->repo->update(f1, f2);
}

vector<Resursa*> Service::getAll()
{
	return this->repo->getAll();
}
