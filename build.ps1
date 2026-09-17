<#
STM32 HAL工程一键编译脚本
自动生成版本头文件version.h，提取git commit hash，记录编译时间
#>
# ===================== 配置区，按需修改 =====================
$KeilPath = "D:\Keil_51\UV4\UV4.exe"  # 改成你电脑UV4.exe真实路径
$ProjectPath = ".\Projects\MDK-ARM\atk_f407.uvprojx"
$VersionHeader = ".\User\version.h"
$AppVersion = "v1.0.0"  # 主版本号，手动修改，脚本自动追加git信息
# ============================================================

# 获取git简短commit哈希，如果不是git仓库就填unknown
try{
    $gitHash = git rev-parse --short HEAD
}catch{
    $gitHash = "unknown"
}
$buildTime = Get-Date -Format "yyyy-MM-dd HH:mm:ss"

# 生成version.h
$headerContent = @"
#ifndef __VERSION_H
#define __VERSION_H

#define FW_APP_VERSION    "$AppVersion"
#define FW_GIT_HASH       "$gitHash"
#define FW_BUILD_TIME     "$buildTime"

#endif
"@
# 写入文件
$headerContent | Out-File -Encoding utf8 $VersionHeader
Write-Host "✅ 版本头文件生成完成: $VersionHeader"
Write-Host "📌 版本:$AppVersion  GIT:$gitHash  编译时间:$buildTime`n"

# 调用Keil命令行编译
& $KeilPath -b $ProjectPath
if($LASTEXITCODE -eq 0){
    Write-Host "`n✅ 编译成功！"
}else{
    Write-Host "`n❌ 编译失败，错误码 $LASTEXITCODE"
    exit $LASTEXITCODE
}
