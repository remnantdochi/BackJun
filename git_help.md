# git 저장소 활용법

일단 먼저 이 글은 visual studio에서 버전 관리를 해보겠다는 시도 였습니다.  
지금 이 깃헙 여기는 원격 저장소, 우리 컴에 있는 건 로컬 저장소  

1. github 사이트에서 master 말고 다른 거 선택할 때 그냥 쓰면 새로 branch 생성됨
2. git repository 만들고 싶은 상위 파일 가서  
`git init`  
`git config user.name "깃허브계정닉네임"`  
`git config user.email "깃허브계정이메일"`  
`git remote add origin 연결하려는 원격 저장소 링크`  
`git checkout -b 생성한 브랜치 이름` : 이건 branch에다 내가 작업하겠다는 것  
`git pull origin 생성한 브랜치 이름` : 이건 원격 저장소 내용을 내가 로컬 저장소에다 내려 받을 것  
3. gitignore  
만약 솔루션 생성된 위치에 git을 만든다면 여러가지 파일이 많으므로 (vcxproj 같은거)  
버전 관리안 할 것을 제외시켜줘야 한다  
.gitignore 파일을 만들어야하는데 윈도우라면 저렇게 만들면 말 안들을거니까  
아무렇게나 만들고 `ren 임시이름 .gitignore`로 바꾸기
파일 열어서 제외할 거 작성  
Debug/  
*.vcxproj  
*.vcxproj.filters  
*.vcxproj.user  
4. 버전 관리할 파일을 어떻게 업로드 할 것인가
`git add 버전 관리할 파일`  
`git commit -m "코멘트" `  
`git push origin 생성한 브랜치 이름`  

**참고**
제가 이렇게 브랜치 만들어서 하는 거는  
pull origin master를 통해서 하게 되면 다른 사람들 코드까지 한 꺼번에 내 컴에 저장되니까
그냥 제 코드 지난 이력만 확인하고 싶어서 branch만들고  
최종 완성하면 따로 올릴려고요  
git push 하다가 뭐 충돌한다 이렇게 에러나면 깃허브로 돌아와서 pull request를 함 봐보세요 master에서  
근데 이게 이 문제인지는 확신이 없음...  
git pull 하면 원격저장소의 폴더가 만들어집니다  
git add 파일위치/파일위치/코드 이렇게 해도 저장됩니다  
아 문제는 제가 이렇게 visual studio에서 돌아가는 건 확인안해봤는데 널부랑

**관련 링크**  
[git 개념](https://backlog.com/git-tutorial/kr/intro/intro1_1.html)  
[마크다운 문법](https://simhyejin.github.io/2016/06/30/Markdown-syntax/)  
  +a) 마크다운에서 다음 줄 넘어가는건 스페이스 2번


