#include "CommonInclude.h"

//사각형 생성 ( 방향키 움직임 )
void SF::GameObject1::Update()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP)) {
		mY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		mY += 0.01f;
	}
}
void SF::GameObject1::LateUpdate()
{
}
void SF::GameObject1::Render(HDC hdc)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));


	Rectangle(hdc, 100.0f + mX, 100.0f + mY, 200.0f + mX, 200.0f + mY);

	SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
	DeleteObject(blueBrush); // 파랑 삭제
	DeleteObject(redPen); //빨강 삭제
}
void SF::GameObject1::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}


/*################################################*/
// 원 생성 ( WASD 움직임 )
void SF::GameObject2::Update()
{
	if (GetAsyncKeyState('A')) {
		mX -= 0.01f;
	}
	if (GetAsyncKeyState('D')) {
		mX += 0.01f;
	}
	if (GetAsyncKeyState('W')) {
		mY -= 0.01f;
	}
	if (GetAsyncKeyState('S')) {
		mY += 0.01f;
	}
}
void SF::GameObject2::LateUpdate()
{
}
void SF::GameObject2::Render(HDC hdc)
{
	HBRUSH redBrush = CreateSolidBrush(RGB(255,0,0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	Ellipse(hdc, 300.0f + mX, 300.0f + mY, 400.0f + mX, 400.0f + mY);

	SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
	DeleteObject(redBrush); // 빨강 삭제
}
void SF::GameObject2::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}

/*################################################*/

SF::Monster::Monster() {
	randomPos = RandomPos();
	dX = direction[randomPos][0];
	dY = direction[randomPos][1];
	posX = 525.0f;
	posY = 525.0f;
}

void SF::Monster::Update()
{
	if (!((posX >= 25 && posX < 1500) && (posY >= 25 && posY < 850))) {
		ChangePos();
	}
	posX += direction[randomPos][0];
	posY += direction[randomPos][1];
}
void SF::Monster::LateUpdate()
{
}
void SF::Monster::Render(HDC hdc)
{
	HBRUSH YBrush = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, YBrush);

	Rectangle(hdc, posX - 25, posY- 25, posX + 25, posY + 25); // size is 50

	SelectObject(hdc, oldBrush);
	DeleteObject(YBrush);
}
int SF::Monster::RandomPos()
{
	srand(time(NULL));
	
	return rand() % 8;
}
void SF::Monster::ChangePos()
{
	if (randomPos == 0) {
		posX += 0.1;
		posY -= 0.1;
		randomPos = rand() % 8;
		if (randomPos == 0)
			randomPos++;
	}
	else if (randomPos == 1) {
		posY -= 0.1;
		randomPos = rand() % 8;
		if (randomPos == 1)
			randomPos++;
	}
	else if (randomPos == 2) {
		posX -= 0.1;
		posY -= 0.1;
		randomPos = rand() % 8;
		if (randomPos == 2)
			randomPos = 7;
	}
	else if (randomPos == 3) {
		posX += 0.1;
		randomPos = rand() % 8;
		if (randomPos == 3)
			randomPos--;
		
	}
	else if (randomPos == 4) {
		posX -= 0.1;
		randomPos = rand() % 8;
		if (randomPos == 4)
			randomPos++;
		
	}
	else if (randomPos == 5) {
		posX += 0.1;
		posY += 0.1;
		randomPos = rand() % 8;
		if (randomPos == 5)
			randomPos = 0;
		
	}
	else if (randomPos == 6) {
		posY += 0.1;
		randomPos = rand() % 8;
		if (randomPos == 6)
			randomPos++;
		
	}
	else if (randomPos == 7) {
		posX -= 0.1;
		posY += 0.1;
		randomPos = rand() % 8;
		if (randomPos == 7)
			randomPos--;
	}


}
void SF::Monster::SetPosition(float x, float y)
{

}


