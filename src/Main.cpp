static RE::BGSKeyword* GetAttachPoint(RE::BSScript::IVirtualMachine&, std::uint32_t, std::monostate, RE::BGSMod::Attachment::Mod* inObjectMod)
{
    return inObjectMod->attachPoint;
}

void RegisterPapyrusScripts(RE::BSScript::IVirtualMachine** vm)
{
    logger::info("registering functions...");
    if (!vm || !*vm) 
    {
        logger::error("vm is nullptr");
        std::exit(0);
    }

    (*vm)->BindNativeMethod(Plugin::Name, "GetAttachPoint", &GetAttachPoint, true, false);
    logger::info("functions registered!");
}

// Main SFSE plugin entry point, initialize everything here
SFSEPluginLoad(const SFSE::LoadInterface* sfse)
{
    Init(sfse);

    logger::info("{} {} is loading...", Plugin::Name, Plugin::Version.string());

    SFSE::SetPapyrusCallback(&RegisterPapyrusScripts, true);

    logger::info("{} has finished loading.", Plugin::Name);

    return true;
}
