## 내일배움캠프 Unreal 트랙 10번 과제
시연 영상 URL : [https://youtu.be/9KO2QQjPeSM]

### 필수 기능
+ `SetUserName()`, `GetUserName()` 이벤트그래프에 노출
    + 각각의 명령어로 `UserName` 저장/불러오기

### 도전 기능
+ GameInstanceSubsystem 을 이용해서 다른 레벨에서도 사용할 수 있도록 만들기
  + `MyIDPluginGameInstanceSubsystem` - `GameInstanceSubsystem` 클래스 상속
    + `SetUserName()`, `GetUserName()` 으로 `UserName` 저장 및 불러오기
+ 필수 기능에서 만든 플러그인은 게임인스턴스에 접근해 위 함수 호출

### 과제 구현하면서 어려웠던 점
+ 플러그인 패키징 오류 발생
  + `Android` 플랫폼도 타겟으로 되어있어 오류가 발생
  + 프로젝트 세팅 등에서 플러그인의 패키징 타겟 플랫폼을 찾아볼 수 없었음
  + 플러그인 폴더의 `.uplugin` 파일을 열어 아래 문구를 추가하여 타겟 플랫폼을 윈도우로 한정하여 해결
    >- SupportedTargetPlatforms": ["Win64"]
    >- "Modules": [ {"Name": "MyIDPlugin", "Type": "Runtime", "LoadingPhase": "PreLoadingScreen", "PlatformAllowList": ["Win64"] }	]

+ 플러그인에서 `GameInstance`에 접근
  + 공식문서에서 `GameInstanceSubsystem`에 접근하기 위한 방법으로 제공한 스니펫은 아래와 같았음
```
UGameInstance* GameInstance = ...;
UMyGameSubsystem* MySubsystem = GameInstance->GetSubsystem<UMyGameSubsystem>();
```
+ 게임 인스턴스 포인터에 현재 게임인스턴스를 할당하고, 그 포인터를 통해 `GetSubsystem()`을 사용하는 것.
+ 그러나 포인터에 현재 게임인스턴스를 할당하는 데에 여러번 시행착오가 있었음
```
UGameInstance* GameInstance = UGameInstance::GetGameInstance() // 실패
UGameInstance* GameInstance = UGameplayStatics::GetGameInstance() // 실패 - 인자로 UObject* WorldContextObject 가 전달되어야함
UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GEngine->GetWorld()); // 실패 - 위 인자에 해당하는 GetWorld()를 전달하려 했으나 어째서인지 GEngine->GetWorld()는 null 이었음
UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(UObject* WorldContextObject); // 절반 성공 - GetGameInstance()의 인자로 블루프린트에서 Get Game Instance 를 전달했더니 문제없이 작동했음.
UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GEngine->GameViewport->GetGameInstance()); // 성공 - 뷰포트를 가져온 다음 뷰포트의 게임 인스턴스를 반환하여 성공함.
```
+ `GetGameInstance()`의 공식 문서상 설명은 `"월드 컨텍스트 오브젝트와 연결된 게임 인스턴스를 반환합니다."`이기 때문에, 게임이 시작한 후에는 명시적이고 일반적으로 존재하는 뷰포트를 지정해 게임 인스턴스를 호출할 수 있다. 
