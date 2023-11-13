#include "CommonInclude.h"
#include "SF_Bullet.h"
#include "SF_Time.h"


SF::Bullet::Bullet() {
	pL = 0.0f;
	pT = 0.0f;
	pR = 0.0f;
	pB = 0.0f;
	bX = 0.0f;
	bY = 0.0f;
	speed = 100.0f;
}

SF::Bullet::~Bullet() {
}

void SF::Bullet::Update() {
	bY -= speed * Time::DeltaTime();
}

void SF::Bullet::Render(HDC hdc) {
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);

	Ellipse(hdc, 50 + pL + bX, 50 + pT + bY, pR + bX - 50, pB + bY - 50);

	SelectObject(hdc, oldBrush);
	DeleteObject(redBrush);
	DeleteObject(redPen);
}

void SF::Bullet::GetPlayerPos(float pL, float pT, float pR, float pB) {
	this->pL = pL;
	this->pT = pT;
	this->pR = pR;
	this->pB = pB;
}
